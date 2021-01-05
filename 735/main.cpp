#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> s;

    for (auto& i: asteroids) {
        if (s.empty() || i > 0 || s.top() < 0)
            s.push(i);
        else
        {
            while (!s.empty() && s.top() > 0) {
                if (i + s.top() < 0) {
                    s.pop();
                    if (s.empty() || s.top() < 0)
                        s.push(i);
                }

                else if (i + s.top() == 0)
                {
                    s.pop();
                    break;
                }
                else if (i + s.top() > 0)
                    break;
            }

        }

    }
    vector<int>ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int>v;
    v.push_back(5);
    v.push_back(-5);
    for (auto& i: asteroidCollision(v))
        cout << i << ' ';
    return 0;
}

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trap(vector<int>& height) {
    int idx = 0;
    int ans=0;
    int preH=0;
    stack<pair<int, int>> s;

    if (height.empty())
        return ans;


    while (idx < height.size()-1) {
        if (height[idx] > height[idx + 1])
            s.push({idx, height[idx]});
        else if (height[idx] < height[idx + 1]) {
            preH=height[idx];
            while (!s.empty()) {
                int h = min(s.top().second, height[idx + 1]);
                ans += (idx - s.top().first) * (h - preH);
                preH = h;
                if (s.top().second >= height[idx+1]){
                    if (s.top().second == height[idx+1])
                        s.pop();
                    break;
                }
                else
                    s.pop();
            }
//            if(s.empty())
//                preH=0;
        }
        idx++;
    }
    return ans;
}

int main() {
    vector<int> v{2,1,0,1,0,1,3,0,1,2,1,0,2,0,1,0,1};
    std::cout << trap(v) << std::endl;
    return 0;
}

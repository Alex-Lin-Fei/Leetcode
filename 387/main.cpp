#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {
    queue<char> que;
    unordered_map<char, int> mp;

    for (int i = 0; i < s.length(); i++) {
        if (!mp.count(s[i])) {
            mp[s[i]] = i;
            que.push(s[i]);
        } else {
            mp[s[i]] = -1;
            while (!que.empty() && mp[que.front()] == -1)
                que.pop();
        }
    }
    return que.empty() ? -1 : mp[que.front()];
}

int main() {
    std::cout <<firstUniqChar("lveevol") << std::endl;
    return 0;
}

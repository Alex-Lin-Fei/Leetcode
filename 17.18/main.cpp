#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int hasFound(vector<int>& big, map<int, set<int>>& m, int l) {
//    每一段
    for (int i = 0; i <= big.size() - l; i++) {
        bool allContain = true;
//        small中的每一个数字
        for (auto &j: m) {
            bool contain = false;
            for (auto &k: j.second) {
                if (k >= i && k < i + l) {
                    contain = true;
                    break;
                }
            }
            if (!contain) {
                allContain = false;
                break;
            }
        }
        if (allContain)
            return i;
    }
    return -1;
}

vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
//    把数字出现的索引存储在set中
    vector<int> ans;
    set<int> s;
    map<int, set<int>> m;
    for (auto &i: small)
        s.insert(i);
    for (int i = 0; i < big.size(); i++) {
        if (s.count(big[i]))
            m[big[i]].insert(i);
    }

//    查看是否包含所有small数字
for (auto& i: small)
    if (!m.count(i))
        return ans;

//    二分法 搜索所有长度
    int minL = small.size();
    int maxL = big.size();
    while (minL <= maxL) {
        int midL = (minL + maxL) >> 1;
        int idx = hasFound(big, m, midL);
        if (idx != -1) {
            maxL = midL - 1;
            ans.clear();
            ans.push_back(idx);
            ans.push_back(idx + midL - 1);
        } else
            minL = midL + 1;
    }

    return ans;
}

int main() {
    vector<int> big{1, 2, 3};
    vector<int> small{4};
    auto ans = shortestSeq(big, small);
    if (!ans.empty())
        cout << ans[0] << ' ' << ans[1] << endl;

    return 0;
}

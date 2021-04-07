#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


bool cross(pair<int, int> a, pair<int, int> b) {
    //保持左侧大于右侧
    if (a.first > b.first)
        swap(a, b);
//    判断重叠
    if (a.second == b.first)
        return true;
//判断交叉
    if (b.first > a.first && b.first < a.second && b.second > a.second)
        return true;
    return false;
}

//找到与cur交叉的区间并得出合并后的范围
void dfs(vector<pair<int, int>> & spaces, int cur, set<int> & visited, int number, vector<pair<int, int>>& temp) {
    visited.insert(cur);
    if (temp.size() == number)
        temp.push_back({spaces[cur]});
    else
        temp[number] = {min(temp[number].first, spaces[cur].first), max(temp[number].second, spaces[cur].second)};

    for (int i = 0; i < spaces.size(); i++) {
        if (!visited.count(i) && cross(spaces[cur], spaces[i])) {
            dfs(spaces, i, visited, number, temp);
        }
    }
}

//dfs
void unite(vector<pair<int, int>> & spaces) {
    int number = 0;
    set<int> visited;
    vector<pair<int, int>> temp;


    for (int i = 0; i < spaces.size(); i++) {
        if (!visited.count(i)) {
            dfs(spaces, i, visited, number, temp);
            number++;
        }
    }

    spaces = temp;
}


void compact(vector<pair<int, int>>& spaces) {
    set<int> hasDeleted;

    for (int i = 0; i < spaces.size(); i++) {
        for (int j = i + 1; j < spaces.size(); j++) {
            if (!hasDeleted.count(j) && spaces[j].second > spaces[i].second && spaces[j].first < spaces[i].first) {
                hasDeleted.insert(j);
            }
        }
    }

    vector <pair<int, int>> temp;
    for (int i = 0; i < spaces.size(); i++)
        if (!hasDeleted.count(i))
            temp.push_back(spaces[i]);
    spaces = temp;
}

vector<string> maxNumOfSubstrings(string s) {
    vector <string> ans;

//    每个字符初始位置确定的区间
    map<char, vector<int>> record;

    for (int i = 0; i < s.length(); i++)
        record[s[i]].push_back(i);



//    获取初始所有区间
    vector <pair<int, int>> spaces;

    for (auto &item: record) {
        if (item.second.size() == 1)
            spaces.emplace_back(item.second[0], item.second[0]);
        else {
            for (int i = 0; i < item.second.size() - 1; i++)
                spaces.emplace_back(item.second[i], item.second[i + 1]);
        }
    }

//    合并区间
    unite(spaces);


//    查看合并区间后的spaces
    cout << "union space: " << endl;
    for (auto &s:spaces)
        cout << s.first << " " << s.second << endl;


    sort(spaces.begin(), spaces.end(), [](pair<int, int> a, pair<int, int> b) {
       return a.second < b.second;
    });
//去除包含区间
    compact(spaces);


    cout << "delete space :\n";
//    查看除去包含区间后的spaces
    for (auto &s:spaces)
        cout << s.first << " " << s.second << endl;


//    得到最多区间数且区间长度和最小  动态规划 两个
//    数组 sum[i]记录以i区间结尾的选法的总长度 而dp[i]记录以i区间结尾的选法的区间数目
    vector<int> sum(spaces.size()), dp(spaces.size()), pre(spaces.size(), -1);

    for (int i = 0; i < spaces.size(); i++) {
        sum[i] = spaces[i].second - spaces[i].first + 1;
        dp[i] = 1;
    }


    int idx = 0;

    for (int i = 1; i < spaces.size(); i++) {
//        找到前一个dp值最大的区间
        for (int j = i - 1; j >= 0; j--) {
            if (spaces[j].second < spaces[i].first) {
                dp[i] += dp[j];
                sum[i] += sum[j];
                pre[i] = j;
                break;
            }
        }

//        记录最大的选法最后一个区间序号
        if (dp[i] > dp[idx] || (dp[i] == dp[idx] && sum[idx] > sum[i]))
            idx = i;
    }


//     确定选择了哪些区间 根据pre数组情况判断

    while (idx != -1) {
        ans.push_back(s.substr(spaces[idx].first, spaces[idx].second - spaces[idx].first + 1));
        idx = pre[idx];
    }

    return ans;
}

class Solution {
public:
    struct Seg {
        int left, right;
        bool operator < (const Seg& rhs) const {
            if (right == rhs.right) {
                return left > rhs.left;
            }
            return right < rhs.right;
        }
    };

    vector<string> maxNumOfSubstrings(string s) {
        vector<Seg> seg(26, (Seg){-1, -1});
        // 预处理左右端点
        for (int i = 0; i < s.length(); ++i) {
            int char_idx = s[i] - 'a';
            if (seg[char_idx].left == -1) {
                seg[char_idx].left = seg[char_idx].right = i;
            } else {
                seg[char_idx].right = i;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (seg[i].left != -1) {
                for (int j = seg[i].left; j <= seg[i].right; ++j) {
                    int char_idx = s[j] - 'a';
                    if (seg[i].left <= seg[char_idx].left && seg[char_idx].right <= seg[i].right) {
                        continue;
                    }
                    seg[i].left = min(seg[i].left, seg[char_idx].left);
                    seg[i].right = max(seg[i].right, seg[char_idx].right);
                    j = seg[i].left;
                }
            }
        }
        // 贪心选取
        sort(seg.begin(), seg.end());
        vector<string> ans;
        int end = -1;
        for (auto& segment: seg) {
            int left = segment.left, right = segment.right;
            if (left == -1) {
                continue;
            }
            if (end == -1 || left > end) {
                end = right;
                ans.emplace_back(s.substr(left, right - left + 1));
            }
        }
        return ans;
    }
};

int main() {
    string s = "abab";
//
    vector<string> ans = maxNumOfSubstrings(s);

    for (auto &str: ans)
        cout << str << endl;

    return 0;
}

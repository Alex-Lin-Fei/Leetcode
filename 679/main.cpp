//#include <iostream>
//#include <vector>
//using namespace std;
//int t;
//bool flag = false;
//
//bool dfs(vector<int>& nums, int idx, int now) {
//    cout << t++ << ':' << idx << " " << now << endl;
//
//    if (idx == nums.size())
//            return now == 24;
//
//    for (int i = idx; i < nums.size(); i++) {
//        swap(nums[i], nums[idx]);
//
//        if (idx == 0) {
//            if (dfs(nums, idx + 1, now + nums[idx])) {
//                return true;
//            }
//
//        }
//        else {
//            if (dfs(nums, idx + 1, now - nums[idx] || dfs(nums, idx + 1, now + nums[idx])
//                                   || dfs(nums, idx + 1, now * nums[idx])))
//                return true;
//            if (now % nums[idx] == 0 && dfs(nums, idx + 1, now / nums[idx]))
//                return true;
//        }
//        swap(nums[i], nums[idx]);
//    }
//
//    return false;
//}
//
//bool judgePoint24(vector<int>& nums) {
//    return dfs(nums, 0, 0);
//}
//
//int main() {
//    vector<int> v(2);
//    for (auto& i: v)
//        cin >> i;
//    cout << judgePoint24(v) << endl;
//    for (auto& i: v)
//        cout << i << ' ';
//    return 0;
//}
//

#include<bits/stdc++.h>
using namespace std;
char l[3] = {'(', '[', '{'};
char r[3] = {')', ']', '}'};
stack<char> s;


int findLeft(char ch) {
    for (int i = 0; i < 3; i++)
        if (l[i] == ch)
            return i;
    return -1;
}

int findright(char ch) {
    for (int i = 0; i < 3; i++)
        if (r[i] == ch)
            return i;
    return -1;
}

bool judge(string& str) {
    while(!s.empty())
        s.pop();
    for (char & i : str) {
        if (findLeft(i) != -1)
            s.push(i);
        else if (findLeft(i) == -1 && s.empty())
            return false;
        else {
            if (findright(i) == findLeft(s.top()))
                s.pop();
            else if (s.empty() || findright(i) != findLeft(s.top()))
                return false;
        }
    }
    return s.empty();
}

int main(){
    string str;
    int n;
    cin >> n;
    while (n--) {
        cin >> str;
        cout << (judge(str)? "Yes": "No") << endl;
    }


    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//vector<vector<string>> groupAnagrams(vector<string>& strs) {
//    vector<vector<string>> ans;
////    枚举每一个字符串
//    for (auto &str: strs) {
////        枚举ans中的每一个字符串
//        bool contain = false;
//        for (auto &a: ans) {
//            if (a[0].length() != str.length())
//                continue;
//            string tmp = a[0];
//            string tmps = str;
//            sort(tmp.begin(), tmp.end());
//            sort(tmps.begin(), tmps.end());
//            if (tmp == tmps) {
//                contain = true;
//                a.push_back(str);
//                break;
//            }
//        }
//        if (contain)
//            continue;
//        else
//            ans.push_back(vector<string>{str});
//    }
//    for (auto &r: ans) {
//        for (auto &s: r)
//            cout << s << ' ';
//        cout << endl;
//    }
//    return ans;
//}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    map<string, vector<string>> record;

    for (auto& str: strs)
    {
        string tmp = str;
        sort(tmp.begin(),tmp.end());
        record[tmp].push_back(str);
    }
    for (auto& iter: record){
        ans.push_back(iter.second);
    }
    return ans;
}

int main() {
    vector<string>v{"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(v);

    return 0;
}

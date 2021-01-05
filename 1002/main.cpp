#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<string> commonChars(vector<string>& A) {
    map<char, pair<int, int>> m;
    for(char & ch: A[0]) {
        if (m.count(ch))
            m[ch].first++;
        else
            m[ch] = make_pair(1, 0);
    }
    for(int i = 1; i<A.size(); i++) {
//        统计当前字符串中字符数
        for (char &ch: A[i]) {
            if (m.count(ch))
                m[ch].second = m[ch].second + 1;
        }

//        删除非共同字符  即second = 0 并更新当前的公共字符数
        for (auto iter = m.begin(); iter != m.end(); ) {
            if (iter->second.second == 0) {
                m.erase(iter++);
            }
            else {
                iter->second.first = min(iter->second.first, iter->second.second);
                iter->second.second = 0;
                iter++;
            }
        }
    }

    vector<string> ans;
    for(auto & iter : m){
        for(int i = 0; i< iter.second.first; i++){
            string s;
            s+=iter.first;
            ans.push_back(s);
        }
    }
    for(auto& s:ans)
        cout << s<<endl;
    return ans;
}

int main() {
    vector<string> strV = {"bella", "label", "roller"};
    commonChars(strV);

    return 0;
}



#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<string> getValidT9Words(string num, vector<string>& words) {
    map<int, set<char> > s;
    vector<string> ans;


    // 填入字典
    char ch = 'a';
    for (int i = 2; i < 10; i++) {
        int num = i == 7 ||i == 9 ? 4: 3;
        while (num--) {
            s[i].insert(ch++);
        }
    }

    for (auto& word: words) {
        if (word.size() == num.size()) {
            int i;
            for (i = 0; i < num.size(); i++) {
                if (!s[num[i]-'0'].count(word[i]))
                    break;
            }
            if (i == num.size())
                ans.push_back(word);
        }
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class CombinationIterator {
private:
    string str;
    vector<int> now;
    bool isFirst;
public:
    CombinationIterator(string characters, int combinationLength) {
        str = std::move(characters);
        now.resize(combinationLength);
        isFirst = true;
    }

    string next() {
        if (isFirst) {
            isFirst = false;
            for (int i = 0; i < now.size(); i++)
                now[i] = i;
        } else {
            int idx = now.size()-1;
            while (idx >= 0) {
                if (now[idx] < str.length() - now.size() + idx) {
                    now[idx]++;
                    for (int i = idx+1; i < now.size(); i++)
                        now[i] = now[i-1]+1;
                    break;
                }
                idx--;
            }
        }
        string nex;
        for (auto &i: now)
            nex += str[i];
        return nex;
    }

    bool hasNext() {
        if (isFirst || now[0] < str.length() - now.size())
            return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    CombinationIterator cmp = CombinationIterator("abcde", 3);
    while (cmp.hasNext())
        cout << cmp.next() <<endl;

    return 0;
}

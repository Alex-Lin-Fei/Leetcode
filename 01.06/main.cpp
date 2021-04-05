#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

string compressString(string S) {
    deque<char>deq;
    vector<int> counts;
    int count = 0;
    string ans;

    for (auto& ch: S) {
        if (deq.empty() || deq.back() != ch) {
            deq.push_back(ch);
            if (count)
                counts.push_back(count);
            count = 1;
        }
        else
            count++;
    }
    counts.push_back(count);

    for (auto& c: counts)
        cout << c<<' ';
    cout << endl;

    for (int c : counts) {
        ans += deq.front();
        ans += to_string(c);
        deq.pop_front();
    }

    return ans.length() < S.length() ? ans: S;
}

int main() {
    string S = "rrrrrLLLLLPPPPPPRRRRRgggNNNNNVVVVVVVVVVDDDDDDDDDDIIIIIIIIIIlllllllAAAAqqqqqqqbbbNNNNffffff";
    cout << compressString(S);

    return 0;
}

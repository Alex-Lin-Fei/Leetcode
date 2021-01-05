#include <iostream>
#include <map>
#include <vector>
using namespace std;


string frequencySort(string);
int main() {
    string s = "ccaaa";
    cout <<frequencySort(s);
}

string frequencySort(string s) {
    map<char, int> count;
    string ans;
    int max_count = 0;
    
    for(char& ch: s)
        max_count = max(max_count, ++count[ch]);
    vector<vector<char>> bucket(max_count+1);

    for(auto& p: count)
        bucket[p.second].push_back(p.first);

    for(int i = max_count; i >=0; i--)
        for(char& ch: bucket[i]) {
            for (int j = 0; j < i; j++)
                ans+=ch;
        }
    return ans;
}

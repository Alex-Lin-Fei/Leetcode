#include <iostream>
#include <vector>
using namespace std;

void getNext(string & str, vector<int>& next) {
    next.resize(str.length());
    next[0] = -1;
    int k = -1;
    int j = 0;

    while (j < str.length() - 1) {
        if (k == -1 || str[k] == str[j]) {
            k++;
            j++;
            if (str[k] != str[j])
                next[j] = k;
            else
                next[j] = next[k];
        } else
            k = next[k];
    }
}

int strStr(string haystack, string needle) {
    if (needle.empty())
        return 0;

    vector<int>next;
    getNext(needle, next);

    int i = 0, j = 0;
    while (i < (int)haystack.length() && j < (int)needle.size()) {
        if (j == -1 || haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }

    if (j == needle.size())
        return i - j;
    else
        return -1;
}


int main() {
    cout << strStr("hello", "ll");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

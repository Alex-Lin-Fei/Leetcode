#include <iostream>
#include <map>
using namespace std;

char findTheDifference(string s, string t) {
    map<char, int> record;

    for (auto &item: s)
        record[item] = (record[item] + 1) % 2;
    for (auto &item: t)
        record[item] = (record[item] + 1) % 2;
    for (auto &item: record)
        if (item.second)
            return item.first;
}

int main() {
    cout << findTheDifference("", "a");

    return 0;
}

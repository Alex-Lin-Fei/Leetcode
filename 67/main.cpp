#include <iostream>
#include <algorithm>

using namespace std;

string addBinary(string a, string b) {
    if (a == "" || b == "")
        return (a == "") ? b: a;
    int indexA = a.size() - 1;
    int indexB = b.size() - 1;
    int r = 0;
    string ans;

    while (indexA >= 0 && indexB >= 0) {
        ans += '0' + (r + (a[indexA] - '0') + (b[indexB] - '0')) % 2;
        r = (r + (a[indexA] - '0') + (b[indexB] - '0')) / 2;
        indexB--;
        indexA--;
    }
    if (indexB < 0) {
        while (indexA >= 0) {
            ans += '0' + (r + (a[indexA] - '0')) % 2;
            r = (r + (a[indexA] - '0')) / 2;
            indexA--;
        }
    }
    else if (indexA < 0) {
        while (indexB >= 0) {
            ans += '0' + (r + (b[indexB] - '0')) % 2;
            r = (r + (b[indexB] - '0')) / 2;
            indexB--;
        }
    }
    cout << r << endl;
    if (r)
        ans += '0' + r;
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string a = "1111";
    string b = "";
    cout << addBinary(a, b);
    return 0;
}

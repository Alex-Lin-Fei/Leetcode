#include <iostream>
#include <utility>
using namespace std;

pair<int,  int> getNum(string str) {
    int real = 0;
    int complex = 0;
    int idx = 0;
    bool isMinusr = false;
    bool isMinusc = false;
    bool isI = false;
    while (idx < str.size() - 1){
        if (str[idx] == '-') {
            if (!isI)
                isMinusr = true;
            else
                isMinusc = true;
            idx++;
            continue;
        }
        if (str[idx] == '+') {
            isI = true;
            idx++;
            continue;
        }
        if (!isI) {
            real *= 10;
            real += str[idx] - '0';
            idx++;
        }
        else {
            complex *= 10;
            complex += str[idx] - '0';
            idx++;
        }
    }
    if (isMinusc)
        complex *= -1;
    if (isMinusr)
        real *= -1;
    return make_pair(real, complex);
}

string complexNumberMultiply(string a, string b) {
    pair<int, int> A = getNum(std::move(a));
    pair<int, int> B = getNum(std::move(b));
    cout << A.first << " " << A.second << endl;
    cout << B.first << " " << B.second << endl;

    string ans;
    int real = A.first * B.first - A.second * B.second;
    int complex = A.second * B.first + A.first * B.second;
    ans += to_string(real) + "+";
    ans += to_string(complex) + "i";
    return ans;
}

int main() {
    cout << to_string(-10);
    cout << complexNumberMultiply("78+-76i", "-86+72i");
    return 0;
}

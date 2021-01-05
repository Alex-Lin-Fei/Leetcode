#include <iostream>
using namespace std;

int brokenCalc(int X, int Y) {
    int ans;
    if (Y <= X) {
        return X - Y;
    }

    else if (Y % 2) {
        return min(brokenCalc(X, (Y + 1) / 2) + 2, brokenCalc(X, Y + 1) + 1);
    }
    else {
        if (X >= Y / 2) {
            ans = X - Y / 2 + 1;
            return ans;
        }

        else {
            return brokenCalc(X, Y / 2) + 1;
        }
    }
}

int main() {
//    cout << brokenCalc(2, 3) << endl;
//
//    cout << brokenCalc(5, 8) << endl;
//    cout << brokenCalc(3, 10) << endl;
//
//    cout << brokenCalc(1024, 1) << endl;
    cout << brokenCalc(1, 1000000000) << endl;

    return 0;
}

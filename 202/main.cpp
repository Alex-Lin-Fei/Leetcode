#include <iostream>
#include <set>
#include <cmath>

using namespace std;

set<int> none{ 4, 16, 37, 58, 89, 145, 42, 20, 4};

int next(int n) {
    int newN = 0;

    while (n) {
        newN += pow((n % 10), 2);
        n /= 10;
    }
    return newN;
}

bool isHappy(int n) {
    int newN = n;

    while (n != 1 && !none.count(newN)) {
        n = newN;
        newN = next(n);
    }

    return n == 1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

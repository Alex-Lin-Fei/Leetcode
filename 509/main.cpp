#include <iostream>
using namespace std;

int fib(int n) {
    int a = 0;
    int b = 1;

    if (n == 0)
        return a;
    else if (n == 1)
        return b;
    else{
        n--;
        while (n--) {
            int tmp =a+b;
            a=b;
            b=tmp;
        }
        return b;
    }
}

int main() {
    std::cout << fib(3) << std::endl;
    return 0;
}

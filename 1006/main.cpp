#include <iostream>
#include <vector>
using namespace std;

int clumsy(int N) {

//    N = In = I(n-1) + 4


//存储一到八的数值
    vector<int> start{0, 1, 2, 6, 7, 7, 8, 6, 9};

    if (N <= 8)
        return start[N];
    else {
        if (N % 4 == 0) {
            return start[8] + 4 * (N / 4 - 2);
        } else {
            return 4 * (N / 4 - 1) + start[4 + N % 4];
        }
    }
}

int main() {

    std::cout << clumsy(11) << std::endl;
    return 0;
}

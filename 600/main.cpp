#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int get(int num, int x, vector<int> & f) {
//    if (num < 3)
//        return 0;
//    if (num == 3)
//        return 1;
//    int sum = accumulate(f.begin(), f.begin() + x, 0);
//
//    int temp = pow(2, x);
//    if (temp <= 4)
//        return sum + 0;
//    else {
//        if (temp / 4 * 3 <= num)
//            return sum + f[x-2] + num - temp/4*3+1;
//        else {
//            if (num >= temp / 2)
//                num -= temp / 2;
//            return sum + get(num, x-2, f);
//        }
//    }
    if (x <= 2)
        return num == 3 ? 1 : 0;
    else {
        int sum = accumulate(f.begin(), f.begin() + x, 0);

        int temp = 3 * pow(2, x - 2);

        if (num >= temp)
            sum += num - temp + 1 + accumulate(f.begin(), f.begin()+x-1, 0);
        else {
//            重新计算num的位数
            temp = pow(2, x - 1);
            if (num >= temp) {
                num -= temp;
            }
//计算位数
            x = 1;
            temp = 2;
            while (temp - 1 < num) {
                x++;
                temp *= 2;
            }
            sum += get(num, x, f);
        }
        return sum;
    }
}

int findIntegers(int num) {
//    求出最大的x满足 2^x - 1 >= num

    if (num <= 2)
        return num + 1;

    if (num == 3)
        return num;

    int x = 1;
    int temp = 2;
    while (temp - 1 < num) {
        x++;
        temp *= 2;
    }

    vector<int> f(x + 1);
    f[1] = 0;
    f[2] = 1;

    int tail = 1;
    for (int i = 3; i < x; i++) {
        f[i] = f[i - 1] + f[i - 2] + tail;
        tail *= 2;
    }

    return num + 1 - get(num, x, f);
}

int main() {

        cout << findIntegers(100)<<endl;
    return 0;
}

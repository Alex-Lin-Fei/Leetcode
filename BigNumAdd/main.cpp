#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct BigNum {
    vector<int> nums;
    int power{};

    void print() const {
        for (int i = nums.size()-1; i>=0;i--)
            cout << nums[i];
        int tmp = power;
        while (tmp--)
            cout << '0';
        cout << endl;
    }
};

void cut(BigNum & A, BigNum& al, BigNum& ah) {
    al.power = A.power;
    ah.power = A.power + A.nums.size() / 2;

    bool isPower = true;
    for (int i = 0; i < A.nums.size(); i++) {
        if (i < A.nums.size() / 2)
            al.nums.push_back(A.nums[i]);
        else {
            if (A.nums[i] == 0 && isPower)
                ah.power++;
            else {
                isPower = false;
                ah.nums.push_back(A.nums[i]);
            }
        }
    }

    while (!al.nums.empty() && al.nums.back() == 0)
        al.nums.pop_back();
    if(al.nums.empty())
        al.nums.push_back(0);
}

BigNum add(BigNum& A, BigNum& B) {
    BigNum bigNum;

    int carry = 0;
    if (A.power > B.power)
        swap(A, B);
    bigNum.power = A.power;
    int zeros = B.power - A.power;
    int a, b;
    for (int i = 0; i < max(A.nums.size(), B.nums.size()+zeros); i++) {
        if (i < zeros || i >= B.nums.size() + zeros)
            b = 0;
        else
            b = B.nums[i - zeros];

        if (i >= A.nums.size())
            a = 0;
        else
            a = A.nums[i];
        bigNum.nums.push_back((a + b + carry) % 10);
        carry = (a + b + carry) / 10;
    }
    if (carry)
        bigNum.nums.push_back(carry);

    return bigNum;
}

BigNum mul(BigNum& A, BigNum& B) {
    if (A.nums.size() / 2 && B.nums.size() / 2) {
//        分治法
//划分数字
        BigNum ah, al; // 50980
        BigNum bh, bl;

        cut(A, al, ah);
        cut(B, bl, bh);

        BigNum r1 = mul(ah, bh);
        BigNum r2 = mul(ah, bl);
        BigNum r3 = mul(al, bh);
        BigNum r4 = mul(al, bl);
        BigNum r5 = add(r1, r2);
        BigNum r6 = add(r3, r4);
        BigNum r7 = add(r5, r6);
        return r7;
    } else {
        BigNum bigNum;
        bool hasSwap = false;

        if (A.nums.size() / 2 == 0) {
            swap(A, B);
            hasSwap = true;
        }

        bigNum.power = A.power + B.power;
        int b = B.nums[0];

        int carry = 0;
        for (auto a: A.nums) {
            bigNum.nums.push_back((a * b + carry) % 10);
            carry = (a * b + carry) / 10;
        }
        if (carry)
            bigNum.nums.push_back(carry);

        if (hasSwap)
            swap(A, B);
        return bigNum;
    }
}

BigNum transfer(string& num) {
    BigNum bigNum;

//    去除num开头的0字符
    reverse(num.begin(), num.end());
    while (num.back() == '0')
        num.pop_back();

    if (num.length() == 0)
        bigNum.nums.push_back(0);
    else {
        bool isPower = true;
        for (char ch : num) {
            if (ch == '0' && isPower)
                bigNum.power++;
            else {
                bigNum.nums.push_back(ch - '0');
                isPower = false;
            }
        }
    }

    return bigNum;
}



int main() {

//    test transfer
//    string num = "";
//    BigNum bigNum = transfer(num);
//    bigNum.print();

//    test add BigNum
//    string num1 = "0124050", num2 = "370100";
//    BigNum A = transfer(num1), B = transfer(num2);
//
//    BigNum bigNum = add(A, B);
//    bigNum.print();

//    test cut
//string num = "124500";
//BigNum bigNum = transfer(num);
//BigNum a, b;
//cut(bigNum, a, b);
//a.print();
//b.print();

    string num1 = "12345098", num2 = "1203";
    BigNum A = transfer(num1), B = transfer(num2);

    BigNum bigNum = mul(A, B);
    bigNum.print();


    return 0;
}

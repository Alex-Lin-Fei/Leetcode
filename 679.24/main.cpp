#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


const int ADD = 0;
const int MULTIPLY = 1;
const int MINUS = 2;
const int DIVIDE = 3;
const double EPSILON = 10e-6;

bool isSolved(vector<double>& list) {
    if (list.size() == 1)
        return fabs(list.front() - 24) < EPSILON;
    if (list.empty())
        return false;

//    枚举操作数
    vector<double> list2;
    for (int i = 0; i < list.size(); i++) {
        for (int j = 0; j < list.size(); j++) {
            if (i == j)
                continue;
            list2.clear();
            for (int h = 0; h < list.size(); h++) {
                if (h != i && h != j)
                    list2.push_back(list[h]);
            }

//            四则运算
            for (int k = 0; k < 4; k++) {
                if (k < 2 && i > j)
                    continue;
                if (k == ADD) {
                    list2.push_back(list[i] + list[j]);
                } else if (k == MULTIPLY) {
                    list2.push_back(list[i] * list[j]);
                } else if (k == MINUS) {
                    list2.push_back(list[i] - list[j]);
                } else if (k == DIVIDE) {
                    if (list[j] < EPSILON)
                        continue;
                    else
                        list2.push_back(list[i] / list[j]);
                }

                if (isSolved(list2))
                    return true;
                list2.pop_back();
            }
        }
    }


    return false;
}

bool judgePoint24(vector<int>& nums) {
    vector<double> list;

    list.reserve(nums.size());
    for (auto item: nums)
        list.emplace_back(static_cast<double>(item));
    return isSolved(list);
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

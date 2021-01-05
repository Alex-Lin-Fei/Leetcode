#include <iostream>
#include <vector>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    if (nums.empty())
        return 0;
    int up = 0, lenup = 1;
    int down = 0, lendown = 1;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > nums[up])
            up = i;
        else if (nums[i] - nums[up] < 0) {
            if (lendown < lenup + 1) {
                lendown = lenup + 1;
                down = i;
            } else if (lendown == lenup + 1 && nums[i] < nums[down])
                down = i;
        }
        if (nums[i] < nums[down])
            down = i;
        else if (nums[i] - nums[down] > 0) {
            if (lenup < lendown + 1) {
                lenup = lendown + 1;
                up = i;
            } else if (lenup == lendown + 1 && nums[i] > nums[up])
                up = i;
        }

//        else if (nums[i] - nums[down] < 0)
//            down = i;
//        else if (nums[i] - nums[up] > 0)
//            up = i;
    }

    return max(lendown, lenup);
}

int main() {
    vector<int> v{33, 53, 12, 64, 50, 41, 45, 21, 97, 35, 47, 92, 39, 0, 93, 55, 40, 46, 69, 42, 6, 95, 51, 68, 72, 9,
                  32, 84, 34, 64, 6, 2, 26, 98, 3, 43, 30, 60, 3, 68, 82, 9, 97, 19, 27, 98, 99, 4, 30, 96, 37, 9, 78,
                  43, 64, 4, 65, 30, 84, 90, 87, 64, 18, 50, 60, 1, 40, 32, 48, 50, 76, 100, 57, 29, 63, 53, 46, 57, 93,
                  98, 42, 80, 82, 9, 41, 55, 69, 84, 82, 79, 30, 79, 18, 97, 67, 23, 52, 38, 74, 15};
    std::cout << wiggleMaxLength(v) << std::endl;
    return 0;
}

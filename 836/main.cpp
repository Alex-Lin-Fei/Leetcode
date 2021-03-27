#include <iostream>
#include <vector>
using namespace std;

bool isLine(vector<int>& rec) {
    return (rec[0] == rec[2] || rec[1] == rec[3]);
}

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
//    判断是否存在矩阵为线段
if (isLine(rec1) || isLine(rec2))
    return false;

    bool left = rec2[2] <= rec1[0];
    bool right = rec2[0] >= rec1[2];
    bool up = rec2[1] >= rec1[3];
    bool down =  rec2[3] <= rec1[1];

    return !(left || right || up || down);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

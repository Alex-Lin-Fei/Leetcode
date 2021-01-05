#include <iostream>
#include <vector>
using namespace std;

class SubrectangleQueries {
private:
    vector<vector<int>> rect;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect.clear();
        rect.resize(rectangle.size());
        for (auto& r: rect)
            r.resize(rectangle[0].size());
        for (int i = 0; i < rectangle.size(); i++)
            for (int j = 0; j < rectangle[0].size(); j++)
                rect[i][j] = rectangle[i][j];
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; i++)
            for (int j = col1; j <= col2;j++)
                rect[i][j] = newValue;
    }

    int getValue(int row, int col) {
        return rect[row][col];
    }
};

int main() {
    vector<vector<int>> v{{0, 1}, {0, 0}};
    v.clear();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

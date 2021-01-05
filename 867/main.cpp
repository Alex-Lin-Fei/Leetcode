#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& A) {
    vector<int> temp;
    vector<vector<int>> ans;
    for (int i = A[0].size()-1; i >= 0; i--) {
        temp.clear();
        for(auto& r: A){
            temp.push_back(r[i]);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

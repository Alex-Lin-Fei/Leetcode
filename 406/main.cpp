#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> ans;
    sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) {
        return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    });

    for (auto& person: people)
        ans.insert(ans.begin() + person[1], person);
    for(auto& i: ans)
        cout << i[0] <<' ' << i[1]<<endl;

    return ans;
}

int main() {
    vector<vector<int>> people{{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    reconstructQueue(people);
    return 0;
}

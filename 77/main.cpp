#include <iostream>
#include <vector>
using namespace std;


void dfs(int idx, int n, int &res, vector<vector<int>> & ans, vector<int> & temp) {
    if (res == 0)
    {
        cout<< "temp:";
        for(auto& i : temp)
            cout << i <<' ';
        cout << endl;
        ans.push_back(temp);
        return;
    }
    for(int i = idx; i<=n; i++) {
        temp.push_back(i);
        res--;
        dfs(i + 1, n, res, ans, temp);
        res++;
        temp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> temp;
    dfs(1, n, k, ans, temp);
    return ans;
}

int main() {
    combine(4,2);

    return 0;
}



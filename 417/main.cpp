#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<int> dir{-1, 0, 1, 0, -1};

//辅函数
void dfs(vector<vector<int>>& matrix, vector<vector<int>>& visited, int x, int y) {
    if(visited[x][y])
        return;
    visited[x][y] = 1;
    for(int k = 0; k < 4; k++)
    {
        int r = x + dir[k];
        int c = y + dir[k+1];
        if (r >= 0 && r < matrix.size() && c >=0 && c < matrix[0].size()
        && matrix[r][c] >= matrix[x][y])
            dfs(matrix, visited, r,c);
    }
}


//从边界开始搜索
vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = m ? matrix[0].size() : 0;

    if(m==0 || n == 0)
        return {};

    vector<vector<int>> visitedP(m, vector<int>(n));
    vector<vector<int>> visitedA(m, vector<int>(n));

    for(int i = 0; i < m; ++i)
    {
        dfs(matrix, visitedP,  i,0);
        dfs(matrix, visitedA, i, n-1);
    }

    for(int i = 0; i < n; i++) {
        dfs(matrix, visitedP, 0, i);
        dfs(matrix, visitedA, m - 1, i);
    }

    vector<vector<int>> ans;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (visitedP[i][j] && visitedA[i][j])
                ans.push_back({i, j});
    return ans;
}
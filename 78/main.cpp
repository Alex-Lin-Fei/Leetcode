//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<vector<int>> ans;
//
//void dfs(vector<int>& nums, vector<int>& temp, int cur) {
//    if (cur == nums.size())
//        ans.push_back(temp);
//    else {
//        temp.push_back(nums[cur]);
//        dfs(nums, temp, cur + 1);
//        temp.pop_back();
//        dfs(nums, temp, cur + 1);
//    }
//}
//
//vector<vector<int>> subsets(vector<int>& nums) {
//    ans.clear();
//    vector<int> temp;
//    dfs(nums, temp, 0);
//    return ans;
//}
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}


#include <iostream>
#include <vector>
using namespace std;

const int MAX_V = 100;

struct Edge{
    int to, cap, rev;
    Edge(int t, int c, int r): to(t), cap(c), rev(r){}
};

vector<Edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap, int rev) {
    G[from].push_back(Edge(to, cap, G[to].size()));
    G[to].push_back(Edge(from, 0, G[from].size()-1));
}

int dfs(int u, int t, int f) {
    if (u == t)
        return f;
    else {
        used[u] = true;
        for (auto& edge: G[u]) {
            if (!used[edge.to] && edge.cap > 0) {
                int d = dfs(edge.to, t, min(f, edge.cap));
                if (d > 0) {
                    edge.cap -= d;
                    G[edge.to][edge.rev].cap += d;
                    return d;
                }
            }
        }
    }
    return 0;
}


int max_flow() {
    int flow{0};
    for(;;) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INT16_MAX);
        if (f > 0)
            flow+=f;
        else
            break;
    }
    return flow;
}
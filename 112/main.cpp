//#include <iostream>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode *left;
//
//    TreeNode *right;
//
//    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};
//
//
//bool hasPathSum(TreeNode* root, int sum) {
//    if (!root)
//        return false;
//    sum -= root->val;
//    if (!root->left && !root->right && sum == 0)
//        return true;
//    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
//}
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int INF = 1<<29;
//int N, T;
//
//int Dijkstra(vector<vector<int> > & grid) {
//    vector<bool> visited(N);
//    vector<int> dist(N, INF);
//
//    dist[0] = 0;
//
//    int minL;
//    int u;
//
//    while (true) {
//        u = -1;
//        minL = INF;
//        for (int i = 0; i < N; i++) {
//            if (!visited[i] && minL > dist[i]) {
//                u = i;
//                minL = dist[i];
//            }
//        }
//        if (u == -1 || u == N - 1)
//            break;
//        visited[u] = true;
//
//        for (int i = 0; i < N; i++)
//            if (!visited[i] && grid[u][i] + dist[u] < dist[i])
//                dist[i] = grid[u][i] + dist[u];
//    }
//    return dist[N - 1];
//}
//
//int main() {
//    int u, v, w;
//
//    cin >> T >> N;
//    vector<vector<int> > grid(N, vector<int>(N, INF));
//
//    for (int i = 0; i < N; i++)
//        grid[i][i] = 0;
//
//    for (int i = 0; i < T; i++) {
//        cin >> u >> v >> w;
//        grid[v - 1][u - 1] = grid[u - 1][v - 1] = w;
//    }
//
//    cout << Dijkstra(grid)<<endl;
//
//    return 0;
//}

//struct Edge {
//    int to, len;
//    Edge(int to, int len) : to(to), len(len) {}
//};
//
//int Dijkstra(vector<Edge> map[]) {
//    vector<long> dist(N, INT16_MAX);
//    vector<bool> visited(N, false);
//
//    dist[0] = 0;
//    int minL;
//    int u;
//    while (true) {
//        u = -1;
//        minL = INT16_MAX;
//
//        for (int i = 0; i < N; i++)
//            if (!visited[i] && dist[i] < minL) {
//                minL = dist[i];
//                u = i;
//            }
//        if (u == -1 || u == N - 1)
//            break;
//
//        visited[u]=true;
//
//        for (int i = 0; i < map[u].size(); i++)
//        {
//            Edge & e = map[u][i];
//            if (!visited[e.to] && dist[u] + e.len < dist[e.to])
//            {
//                dist[e.to] = dist[u] + e.len;
//            }
//        }
//    }
////    for (auto& i: dist)
////        cout << i << ' ';
////    cout << endl;
//    return dist[N-1];
//}
//
//int main() {
//    int u ,v ,w;
//    cin >> N >> T;
//    vector<Edge> map[N];
//
//    for (int i = 0; i < T; i++)
//    {
//        cin >> u >> v >>w;
//        map[u-1].push_back(Edge(v-1, w));
//        map[v-1].push_back(Edge(u-1, w));
//    }
//
//    cout << Dijkstra(map)<< endl;
//    return 0;
//}


#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

const int INF = 1<<29;

int T, N;

//vector<int> Map[maxn][maxn],ans[maxn];
//bool vis[maxn];

int Dijkstra(vector<vector<int> > & Map, int cur,int n)    ///普通版
{
    vector<bool> vis(N);
    vector<int> ans(N, INF);

//    int i,j,k,Min;
//    for(i=0;i<n;i++)
//        ans[i]=Map[cur][i];//如果当前点距离其他点有边 那么距离就是长度
//    //因为在调用函数之前 遍历赋值过INF 所以如果离当前顶点没有边就是INF 不会进入下面的分支
//
//    vis[cur]=true;
//    ans[cur]=0;//起点距离自己的距离是0
//
//    //从1一直找到n
//    for(i=0;i<n;i++)
//    {
//        //找当前点下一步的最短路
//        Min=INF;
//        for(j=0;j<n;j++)
//            if(!vis[j] && Min>ans[j])
//            {
//                k=j;
//                Min=ans[j];
//            }
//        vis[k]=true;
//
//        //计算所有该点（上面找到的最小值）能到达的点的可能的最短路径
//        for(j=0;j<n;j++)
//            if(!vis[j] && Min+Map[j][k]<ans[j])/***/
//                ans[j]=Min+Map[k][j];
//    }
    ans[0] = 0;
    int minL;
    int u;
    while (true) {
        u = -1;
        minL = INF;

        for (int i = 0; i < N; i++)
            if (!vis[i] && ans[i] < minL) {
                minL = ans[i];
                u = i;
            }
        if (u == -1 || u == N - 1)
            break;

        vis[u]=true;

        for (int i = 0; i < N; i++)
        {
            if (!vis[i] && ans[u] + Map[u][i] < ans[i])
            {
                ans[i] = ans[u] + Map[u][i];
            }
        }
    }

    return ans[N-1];
}

int main()
{
    cin >> T >> N;

    vector<vector<int> > Map(N, vector<int>(N));
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
            Map[i][j] = INF;

    for(int i = 1;i <= T;i++)
    {
        int a, b, v;
        scanf("%d %d %d", &a, &b, &v);

        if(v < Map[a-1][b-1])
        {
            Map[a-1][b-1] = Map[b-1][a-1] = v;
        }
    }

    cout << Dijkstra(Map, 0, N) << endl;

    return 0;
}


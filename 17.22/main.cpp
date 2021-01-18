#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isNear(string& s1, string& s2) {
    int diff=1;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i])
            diff--;
        if (diff < 0)
            return false;
    }
    return true;
}


vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<string> ans;
    auto iter = find(wordList.begin(), wordList.end(), endWord);

    if (iter == wordList.end())
        return ans;
    int target = iter - wordList.begin()+1;


    // 邻接矩阵
    vector<vector<int>> nearList(wordList.size() + 1);

    // 构图
    for (int i = 0; i< wordList.size(); i++)
        if (isNear(beginWord, wordList[i])) {
            nearList[0].push_back(i+1);
            nearList[i+1].push_back(0);
        }

    for (int i = 0; i< wordList.size(); i++) {
        for (int j = i+1; j < wordList.size(); j++) {
            if (isNear(wordList[i], wordList[j])) {
                nearList[i+1].push_back(j+1);
                nearList[j+1].push_back(i+1);
            }
        }
    }

    // Dijkstra 最短路径
    vector<int> dist(wordList.size()+1, INT32_MAX);
    vector<int> pre(wordList.size()+1, -1);
    vector<bool> visited(wordList.size()+1);

    dist[0] = 0;
    int nex;
    int shortest;

    while(true) {
        nex = -1;
        shortest = INT32_MAX;
        // 找出最近的节点
        for (int i = 0; i < dist.size(); i++) {
            if (!visited[i] && dist[i] < shortest) {
                nex = i;
                shortest = dist[i];
            }
        }

        if (nex == -1)
            break;
        visited[nex] = true;
        if (nex == target)
            break;

        // 更新前驱节点
        for (int i = 0; i < dist.size(); i++) {
            if (!visited[i] && find(nearList[nex].begin(), nearList[nex].end(), i)!= nearList[nex].end() && dist[i] > dist[nex] + 1)
            {
                dist[i] = dist[nex] + 1;
                pre[i] = nex;
            }
        }
    }

    if (pre[target] == -1)
        return ans;

    // 提取所有前驱节点
    while(target != -1) {
        if(target == 0)
            ans.push_back(beginWord);
        else
            ans.push_back(wordList[target-1]);
        target = pre[target];
    }
    reverse(ans.begin(), ans.end());

    return ans;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

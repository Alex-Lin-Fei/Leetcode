#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool func(string & a, string & b) {
    if (a.length() != b.length() || a == b)
        return false;
    int cnt = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            if (cnt != 0)
                return false;
            else
                cnt++;
        }
    }
    return cnt == 1;
}


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int u = -1;
    for (int i = 0; i < wordList.size(); i++)
        if (wordList[i] == endWord)
        {
            u = i;
            break;
        }
    if (u == -1)
        return 0;

    u++;
    vector<vector<int>> graph(1 + wordList.size(), vector<int>());
    vector<bool> visited(wordList.size() + 1);
    for (int i = 0; i < wordList.size(); i++) {
        if (func(beginWord, wordList[i])) {
            graph[0].push_back(i + 1);
            graph[i+1].push_back(0);
        }
    }

    for (int i = 0; i < wordList.size(); i++)
        for (int j = i + 1; j < wordList.size(); j++) {
            if (func(wordList[i], wordList[j])) {
                graph[i + 1].push_back(j + 1);
                graph[j + 1].push_back(i + 1);
            }
        }

    queue<int> que;
    que.push(0);
    visited[0] = true;
    int level = 0;
    bool f = false;
    while (!que.empty()) {
        if (f)
            break;
        int size = que.size();
        level++;
        while (size--) {
            int v = que.front();
            que.pop();
            if (v == u) {
                f = true;
                break;
            }
            for (auto &i: graph[v])
                if (!visited[i]) {
                    visited[i] = true;
                    que.push(i);
                }
        }
    }

    return f?level: 0;
}

int main() {
    vector<string> wordList{"hot","dot","dog","lot","log"};
    string beginWord = "hit";
    string endWord = "cog";
    std::cout << ladderLength(beginWord, endWord, wordList) << std::endl;
    return 0;
}

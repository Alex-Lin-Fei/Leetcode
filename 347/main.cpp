#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;

    map<int, int> m;
    int max_count=0;
    for(int & num: nums)
        max_count = max(max_count, ++m[num]);
    vector<vector<int>> v(max_count+1);

    for(auto& p: m)
        v[p.second].push_back(p.first);

    for(int i = max_count; i>=0 &&ans.size()< k; i--)
        for(auto& num: v[i]){
            ans.push_back(num);
            if(ans.size()==k)
                break;
        }
    return ans;
}

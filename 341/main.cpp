#include <iostream>
#include <vector>
using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
private:
    vector<int> nums;
    int cur;
    void dfs(const vector<NestedInteger>& nestedInteger) {
        for (auto& item: nestedInteger) {
            if (item.isInteger())
                nums.push_back(item.getInteger());
            else
                dfs(item.getList());
        }
    }
public:
    NestedIterator(vector <NestedInteger> &nestedList) {
        dfs(nestedList);
        cur=0;
    }

    int next() {
        return nums[cur++];
    }

    bool hasNext() {
        return cur != nums.size();
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

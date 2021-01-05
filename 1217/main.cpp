#include <iostream>
#include <vector>
using namespace std;

int minCostToMoveChips(vector<int>& chips) {
    int odds=0;
    int evens=0;
    for (int &i: chips)
        if (i % 2)
            odds++;
        else
            evens++;
    return max(odds, evens);

}

int main() {
    return 0;
}

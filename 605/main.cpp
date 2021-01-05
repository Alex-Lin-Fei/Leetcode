#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    for (int i = 0; i < flowerbed.size(); i++) {
        if(n==0)
            return true;
        if (flowerbed[i] == 0) {
            if ((i == 0 && (i + 1 >= flowerbed.size() || flowerbed[i + 1] == 0) || i == flowerbed.size() - 1 && (i-1< 0 || flowerbed[i - 1] == 0))
                || ((i + 1 >= flowerbed.size() || flowerbed[i + 1] ==0) && (i-1< 0 ||flowerbed[i - 1] == 0))) {
                n--;
                flowerbed[i] = 1;
            }
        }
    }
    for(auto& i: flowerbed)
        cout <<i<<' ';
    return n == 0;
}

int main() {
    vector<int>v{0};
    std::cout << canPlaceFlowers(v,1) << std::endl;
    return 0;
}

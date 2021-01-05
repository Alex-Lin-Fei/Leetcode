#include <iostream>
#include <vector>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int fives = 0, tens = 0, twenties = 0;
    for (auto &bill: bills) {
        switch (bill) {
            case 5:
                fives++;
                break;
            case 10: {
                fives--;
                tens++;
            }
                break;
            case 20:{
                if (tens>0)
                {
                    tens--;
                    fives--;
                }
                else{
                    fives-=3;
                }
                twenties++;
            }
                break;
            default:
                break;
        }
        if (fives<0 || tens<0)
            return false;
    }
    return true;
}

int main() {
    vector<int> bills{5,5,10,10,20};
    std::cout << lemonadeChange(bills) << std::endl;

    return 0;
}

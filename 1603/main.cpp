#include <iostream>
#include <vector>
using namespace std;


class ParkingSystem {
private:
    vector<int>space;
public:
    ParkingSystem(int big, int medium, int small) {
        space.push_back(big);
        space.push_back(medium);
        space.push_back(small);
    }

    bool addCar(int carType) {
        if (space[carType - 1] > 0) {
            space[carType - 1]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

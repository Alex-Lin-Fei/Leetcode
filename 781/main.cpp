#include <iostream>
#include <vector>
#include <map>
using namespace std;

int numRabbits(vector<int>& answers) {
    map<int, int> rabbits;

    for (auto& answer: answers) {
        if (rabbits.count(answer)) {
            rabbits[answer]--;
            if (rabbits[answer] == 0)
                rabbits.erase(answer);
        } else if (answer != 0){
            rabbits[answer] = answer;
        }
    }

    int ans = answers.size();

    for (auto& rabbit: rabbits)
        ans += rabbit.second;

    return ans;
}

int main() {
    vector<int> answers{};
    std::cout << numRabbits(answers) << std::endl;
    return 0;
}

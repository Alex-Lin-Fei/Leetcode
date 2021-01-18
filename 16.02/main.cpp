#include <iostream>
#include <map>
#include <vector>
using namespace std;


class WordsFrequency {
private:
    map<string ,int> count;
public:
    explicit WordsFrequency(vector<string>& book) {
        for (auto& b: book)
            count[b]++;
    }

    int get(const string& word) {
        return count[word];
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

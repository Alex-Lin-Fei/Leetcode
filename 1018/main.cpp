#include <iostream>
#include <vector>
using namespace std;

vector<bool> prefixesDivBy5(vector<int>& A) {
    int status = -1;
    vector<bool> ans;

    for (auto& i: A) {
        switch (status) {
            case -1: {
                if (i == 0)
                    status = 0;
                else
                    status = 1;
            }
                break;
            case 0: {
                if (i == 0)
                    status = 0;
                else
                    status = 1;
            }
                break;
            case 1: {
                if (i == 0)
                    status = 2;
                else
                    status = 3;
            }
                break;
            case 2: {
                if (i == 0)
                    status = 4;
                else
                    status = 0;
            }
                break;
            case 3: {
                if (i == 0)
                    status = 1;
                else
                    status = 2;
            }
                break;
            case 4: {
                if (i == 0)
                    status = 3;
                else
                    status = 4;
            }
                break;
        }
        ans.push_back(status == 0);
    }
    for (auto item : ans)
        cout << item <<' ';
    return ans;
}

int main() {

    return 0;
}

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

//vector: 用于保存同列的第0~i行元素和
vector<vector<int>>cols;
vector<int> ans;

void initCols(vector<vector<int>>& matrix) {
    cols.clear();
    ans.clear();
    cols.resize(matrix.size()+1, vector<int>(matrix[0].size(), 0));
    ans.resize(matrix[0].size());

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cols[i+1][j] = cols[i][j] + matrix[i][j];
        }
    }
}

//求出第i~j行矩阵元素列相加的vector
void getItoJ(vector<vector<int>>& matrix, int i, int j) {
    for (int k = 0; k < ans.size(); k++) {
        ans[k] = cols[j + 1][k] - cols[i][k];
    }
}

//求最大连续子序列 二分法
tuple<int, int, int> getCrossSum(int l, int r) {
    int mid = (l + r)>>1;
    int sum;

    sum = 0;
    int leftSum = INT32_MIN, maxl = mid;
    for (int i = mid; i >= l; i--) {
        sum += ans[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxl = i;
        }
    }

    sum = 0;
    int rightSum = INT32_MIN, maxr = mid;
    for (int i = mid + 1; i <= r; i++) {
        sum += ans[i];
        if (sum > rightSum) {
            rightSum = sum;
            maxr = i;
        }
    }

    return make_tuple(maxl, maxr, leftSum + rightSum);
}

tuple<int, int, int> getSum(int l, int r) {
    if (l == r)
        return make_tuple(l, l, ans[l]);
    else {
        int mid = (l + r) >> 1;
        auto C = getCrossSum(l, r);
        auto L = getSum(l, mid);
        auto R = getSum(mid + 1, r);
        if (get<2>(C) >= get<2>(L) && get<2>(C) >= get<2>(R))
            return C;
        else if (get<2>(C) <= get<2>(L) && get<2>(L) >= get<2>(R))
            return L;
        else
            return R;
    }
}

tuple<int, int, int> getSum2(int l, int r) {
    int nStart = ans[0];
    int nAll = ans[0];
    int maxl = 0, maxr = 0;
    int tl = 0, tr = 0;

    for (int i = 1; i < ans.size(); i++) {
        if (nStart < min(0, ans[i])) {
            nStart = 0;
            tl = i;
        }
        nStart += ans[i];
        tr = i;
        if (nStart > nAll)
        {
            nAll = nStart;
            maxl = tl;
            maxr = tr;
        }
    }
    return make_tuple(maxl, maxr, nAll);
}




vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
    vector<int> res(4);
    initCols(matrix);

    int M = INT32_MIN;


    for (int i = 0; i < matrix.size(); i++) {
        for (int j = i; j < matrix.size(); j++) {
            getItoJ(matrix, i, j);
            auto C = getSum2(0, ans.size() - 1);

            if (get<2>(C) > M) {
                M = get<2>(C);
                res = {i, get<0>(C), j, get<1>(C)};
            }
        }
    }
    return res;
}

int main() {
    vector<vector<int>> matrix{{-5208,  1041,   -93779, -64152, 17850,  29055,  -63731, -23568, 41170,  58457,  -39616, 55683,  -51662, -75015, 21726},
                               {4535,   -72412, 86878,  -60825, 67088,  48794,  -23471, -22403, 58200,  -31153, -94668, -27274, -11003, 33894,  -66125},
                               {-9538,  -33861, 54822,  42636,  48430,  -56030, -33348, -30617, 5219,   56501,  -95879, -73537, -18157, -72815, -40977},
                               {15602,  40115,  -32475, 99011,  47251,  84035,  83793,  -74389, -99042, 65460,  11671,  -95294, 68311,  47893,  71866},
                               {69607,  57288,  55022,  36610,  -75113, 31344,  34319,  -13381, -74800, -71904, -15625, -5398,  -29689, -68805, -41994},
                               {-32276, 95017,  -96452, -47311, 13238,  46324,  95358,  13247,  -30930, 5815,   -36748, -25712, -83982, 29391,  -73922},
                               {-29140, -70403, -3168,  12219,  -4473,  -10013, -85502, 87222,  -44858, 66506,  -99821, -16992, -80758, 59210,  87145},
                               {-9557,  67725,  -27359, -28647, 46781,  -67948, -28154, -3498,  91489,  -3887,  -96422, 6568,   42380,  73264,  -55406},
                               {40555,  70153,  -51490, -14237, 9684,   -54000, -8443,  -32063, -96157, -70083, -7050,  56221,  93013,  -1157,  -45593},
                               {-28686, -54296, 628,    11189,  18227,  -64455, -10528, -69244, 94796,  -39806, 69194,  45024,  -14417, -51291, 6387},
                               {-28485, 36898,  97259,  -83875, 83650,  -36715, 80692,  -55055, 40025,  -69379, -1548,  -13045, 23318,  79349,  -42774},
                               {82645,  17721,  84052,  -35036, -751,   90269,  -77187, 51972,  -90217, -5956,  -34552, 95560,  40436,  51650,  72778},
                               {-970,   77788,  10423,  -1406,  -90844, 6732,   -60197, 59393,  -82111, 33737,  -4731,  -52679, -12011, 69741,  -91931}};
    auto a = getMaxMatrix(matrix);
    for (auto &i: a)
        cout << i << ' ';

    getItoJ(matrix, 1, 5);

    return 0;
}

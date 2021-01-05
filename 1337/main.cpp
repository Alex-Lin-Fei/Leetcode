#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

//struct V{
//    vector<int>v;
//    int idx;
//    V(vector<int>ve, int i): v(std::move(ve)), idx(i){}
//    bool operator<(const V& x) const {
////        int l = 0;
////        int r = v.size();
////        while (l <= r) {
////            int mid = (l+r)>>1;
////            if (v[mid] > x.v[mid])
////                return false;
////            else if (v[mid] < x.v[mid])
////                return true;
////            else {
////                if (v[mid] == 0)
////                    r = mid-1;
////                else
////                    l = mid+1;
////            }
////        }
////        return false;
//        for(int i = 0; i < v.size(); i++) {
//            if (v[i] < x.v[i])
//                return true;
//            else if (v[i]> x.v[i])
//                return false;
//            else
//                break;
//        }
//        return idx < x.idx;
//    }
//};

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//    vector<V>vs;
//    vector<int>ans;
//    for (int i = 0; i < mat.size(); i++)
//        vs.push_back(V(mat[i], i));
//    sort(vs.begin(), vs.end());
//
//    for (int i = 0; i <vs.size(); i++) {
//        ans.push_back(vs[i].idx);
//        cout << vs[i].idx<<' ';
//    }
//    return ans;
     vector<pair<int, int>> vp;
     vector<int>ans;
     for (int i = 0; i < mat.size(); i++){
         int sum=0;
         for (auto j : mat[i])
             sum += j;
         vp.emplace_back(sum, i);
     }
     sort(vp.begin(), vp.end());
     for (auto&i: vp)
         cout<<i.second<<' ';
}

int main() {
    vector<vector<int>> mat = {{1,0,0,0},
    {1,1,1,1},
    {1,0,0,0},
    {1,0,0,0}};
    kWeakestRows(mat, 2);
    return 0;
}

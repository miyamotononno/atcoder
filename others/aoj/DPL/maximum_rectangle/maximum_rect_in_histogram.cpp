#include <bits/stdc++.h>
#include "module.hpp"
using namespace std;
typedef long long ll;

// ヒストグラムの中の最大長方形問題
// https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_C

int main(){
    int N;
    cin >> N;
    vector<ll> hist(N);
    for (int i=0;i<N;i++) cin >> hist[i];
    
    cout << calcMaximumHistogram(hist) << endl;
    return 0;
}
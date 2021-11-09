#include <bits/stdc++.h>
#include "module.hpp"
using namespace std;

/*
最大長方形問題
https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_B
*/


int calcMaximumArea(const vector<vector<int>>& memo) {
    int ans = 0;
    for (int h=0; h<memo.size(); h++) {
        vector<int> d = memo[h];
        // for_each(d.begin(), d.end(), [](int x) { std::cout << x << ","; });
        ans = max(ans, calcMaximumHistogram(d));
    }
    return ans;
}

int main(){
    int H, W;
    cin >> H >> W;
    char blocks[H][W];
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            cin >> blocks[i][j];
        }
    }
    vector<vector<int>> memo(H, vector<int>(W)); // 上にどれだけの高さがあるか
    for (int h=0; h<H; h++) { 
        for (int w=0; w<W; w++) {
            if (h==0) {
                memo[0][w] = blocks[0][w]=='.'?1:0;
                continue;
            }
            memo[h][w] = blocks[h][w]=='.'?memo[h-1][w]+1:0;
        }
    }
    
    cout << calcMaximumArea(memo) << endl;
    return 0;
}
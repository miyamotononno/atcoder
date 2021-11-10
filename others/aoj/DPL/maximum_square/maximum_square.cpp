#include <bits/stdc++.h>
using namespace std;

int calc(vector<vector<int>> inputs) {
  int H = inputs.size();
  int W = inputs[0].size();
  int D[H][W];
  int ans = 0;
  for (int i=0; i<H; i++) {
    D[i][0] = inputs[i][0]==0?1:0;
    if (inputs[i][0]==0) ans = 1;
  }
  for (int i=0; i<W; i++) {
    D[0][i] = inputs[0][i]==0?1:0;
    if (inputs[0][i]==0) ans = 1;
  }
  for (int i=1; i<H; i++) {
    for (int j=1; j<W; j++) {
      D[i][j] = min({D[i-1][j], D[i-1][j-1], D[i][j-1]})+1;
      if (inputs[i][j]==1) D[i][j] = 0;
      ans = max(ans, D[i][j]);
    }
  }
  return ans*ans;
}

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<int>> D(H, vector<int>(W));
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> D[i][j];
    }
  }
  cout << calc(D) << endl;
}
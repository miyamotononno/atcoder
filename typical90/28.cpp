#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n;
int a[1002][1002], sumx[1002][1002], sumy[1002][1002];

const int maxSize = 1000;


// 二次元いもす法
int main() {
  cin >> n;
  int lx,ly,rx,ry;
  //　対角で+1, もう一つの対角で-1
  for (int i=0; i<n; i++) {
    cin >> lx >> ly >> rx >> ry;
    a[lx][ly]++; a[rx][ry]++;
    a[lx][ry]--; a[rx][ly]--;
  }

  // 横方向に累積和をとる
  for (int x=0; x<=maxSize; x++) {
    for (int y=0; y<=maxSize; y++) {
      if (x==0) sumx[x][y] = a[x][y];
      else sumx[x][y] = sumx[x-1][y] + a[x][y];
    }
  }

  // 縦方向に累積和をとる
  for (int y=0; y<=maxSize; y++) {
    for (int x=0; x<=maxSize; x++) {
      if (y==0) sumy[x][y] = sumx[x][y];
      else sumy[x][y] = sumy[x][y-1] + sumx[x][y];
    }
  }

  vector<int> ans(n+1, 0); 
  for (int x=0; x<=maxSize; x++) {
    for (int y=0; y<=maxSize; y++) {
      ans[sumy[x][y]]++;
    }
  }
  for (int i=1; i<=n; i++) {
    cout << ans[i] << endl;
  }
}
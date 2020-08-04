#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <limits>
#define rep(i,n) for (int i=0; i<n;++i)
using namespace std;
typedef long long ll;
const int INF = 1e9;
int H, W, d[10][10];

void warshall_floyd() {
  rep(k, 10){
    rep(i, 10){
      rep(j, 10) d[i][j] =min(d[i][j], d[i][k]+d[k][j]);
    }
  }
}

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> H >> W;
  rep(i, 10){
    rep(j, 10) cin >> d[i][j];
  }

  warshall_floyd();
  int sm = 0;
  rep(i, H){
    rep(j, W) {
      int a;
      cin >> a;
      if (a<0) continue;
      sm += d[a][1];
    }
  }
  cout << sm << endl;
  return 0;
}
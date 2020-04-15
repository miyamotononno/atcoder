#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int H, W;
int a[501][501];
struct edge {int fromh, fromw, toh, tow; };
vector<edge> Ans;
int S[501][501];
queue<int> que;

// 右か下に動かす。
void calc(int h, int w) {
  if (w<W-1) {
    edge e = {h, w, h, w+1};
    a[h][w+1]++;
    a[h][w]--;
    Ans.push_back(e);
  } else if (h<H-1){
    edge e = {h, w, h+1, w};
    a[h+1][w]++;
    a[h][w]--;
    Ans.push_back(e);
  }
} 

int main() {
  INCANT;
  cin >> H >> W;
  rep(i, H) rep(j, W) cin >> a[i][j];

  rep(i, H) {
    rep(j, W) {
      if (a[i][j]%2==0) continue; 
      calc(i, j);
    }
  }
  cout << Ans.size() << endl;
  rep(i, Ans.size()) {
    edge e = Ans[i];
    cout << e.fromh+1 << ' ';
    cout << e.fromw+1 << ' ';
    cout << e.toh+1 << ' ';
    cout << e.tow+1 << endl;
  }
  return 0;
}
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
int N, Q;
struct edge {double x,r,h;};
edge es[103];
int Query[100005][2];
typedef pair<double, double> P;

P get_h_and_r(int idx, double x){ // idxとx座標から半径と高さを求める
  edge e = es[idx];
  if (x<=e.x) return P(e.r, e.h);
  if (x>=e.x+e.h) return P(0,0);
  return P(e.r*(e.h-(x-e.x))/e.h, e.h-(x-e.x));
}
  

double calc(int idx, double a, double b) {
  P p1 = get_h_and_r(idx, a);
  P p2 = get_h_and_r(idx, b);
  return pow(p1.first, 2)*PI*p1.second/3 - pow(p2.first, 2)*PI*p2.second/3;
}

int main() {
  INCANT;
  cin >> N >> Q;
  rep(i, N) cin >> es[i].x >> es[i].r >> es[i].h;
  rep(i, Q) cin >> Query[i][0] >> Query[i][1];
  rep(i, Q) {
    double SUM=0.0;
    rep(j, N) SUM+=calc(j, Query[i][0], Query[i][1]);
    cout << SUM << endl;
  }
  return 0;
}
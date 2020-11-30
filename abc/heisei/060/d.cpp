#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n;
ll W, w[102];
int v[102];
vector<int> d[4];
int sumV[4][101];

int main() {
  INCANT;
  cin >> n >> W;
  rep(i, n) {
    cin >> w[i] >> v[i];
    d[w[i]-w[0]].push_back(v[i]);
  }
  rep(i, 4) sort(ALL(d[i]), greater<int>());
  rep(i, 4) {
    int val = 0;
    rep(j, d[i].size()+1) {
      sumV[i][j] = val;
      if (j<d[i].size()) val+=d[i][j];
    }
  }
  int size0 = d[0].size();
  int size1 = d[1].size();
  int size2 = d[2].size();
  int size3 = d[3].size();

  int maxVal = 0;
  rep(i, size0+1) {
    rep(j, size1+1) {
      rep(k, size2+1) {
        rep(l, size3+1) {
          if (w[0]*i+(w[0]+1)*j+(w[0]+2)*k+(w[0]+3)*l>W) continue;
          maxVal = max(maxVal, sumV[0][i]+sumV[1][j]+sumV[2][k]+sumV[3][l]);
        }
      }
    }
  }
  cout << maxVal << endl;

  
  return 0;
}
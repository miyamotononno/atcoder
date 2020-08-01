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
typedef long long ll;
using namespace std;
int N, Q, Query[100005][3];
ll rowP[100005], colP[100005];


int main() {
  INCANT;
  cin >> N >> Q;
  rep(i, Q) {
    cin >> Query[i][0];
    if (Query[i][0]==3) continue;
    cin >> Query[i][1] >> Query[i][2];
    Query[i][1]--;Query[i][2]--;
  }
  rep(i, N) rowP[i]=(ll)N*i;
  rep(i, N) colP[i]=(ll)i;

  bool trans = false;
  rep(i, Q) {
    if (Query[i][0]==3) {
      trans=!trans;
      continue;
    }
    int x = Query[i][1];
    int y = Query[i][2];
    if (Query[i][0]==4) {
      if (!trans) cout << rowP[x]+colP[y] << endl;
      else cout << rowP[y]+colP[x] << endl;
    }
    if (Query[i][0]==1) {
      if (x == y) continue;
      if (trans) swap(colP[x], colP[y]);
      else swap(rowP[x], rowP[y]);
    }
    if (Query[i][0]==2) {
      if (x == y) continue;
      if (!trans) swap(colP[x], colP[y]);
      else swap(rowP[x], rowP[y]);
    }
  }
  return 0;
}
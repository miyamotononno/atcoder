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
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int A, B, M;
int a[100004], b[100004];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B >> M;
  int mina = INF, minb=INF;
  rep(i, A) {
    cin >> a[i];
    mina = min(a[i], mina);
  }
  rep(i, B) {
    cin >> b[i];
    minb = min(b[i], minb);
  }
  int minx = mina+minb;
  int x=0,y=0,c=0;
  rep(i, M) {
    cin >> x >> y >>c;
    x--;y--;
    minx = min(a[x]+b[y]-c, minx);
  }

  cout << minx << "\n";
  return 0;
}
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
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int N, K;
long double E[200005];
long double SUM[200005];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  long double a;
  rep(i, N) {
    cin >> a;
    E[i] = (a+1)/2;
  }
  rep(i, K) {
   SUM[0] += E[i];
  }
  rep(i, N-K+1) {
    if (i==0) continue;
    SUM[i] = SUM[i-1] - E[i-1]+E[i+K-1];
  }
  long double mx = 0;
  rep(i, N-K+1) mx = max(mx, SUM[i]);
  cout << setprecision(7) << mx << "\n";
  return 0;
}
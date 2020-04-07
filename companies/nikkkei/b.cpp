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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
typedef long long ll;
using namespace std;
const ll MOD = 998244353;
int N, D[100001];
ll C[100001];

int main() {
  INCANT;
  cin >> N;
  rep(i, N) {
    cin >> D[i];
    C[D[i]]++;
  }
  ll ans = (C[0]>1 || D[0]!=0)?0ll:1ll;
  for (int i=1; i<N; i++) {
    ans*=C[D[i]-1];
    ans%=MOD;
  }
  cout << ans << "\n";
  return 0;
}
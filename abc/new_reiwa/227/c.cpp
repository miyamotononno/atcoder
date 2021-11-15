#include <bits/stdc++.h>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
ll n;

int main() {
  INCANT;
  cin >> n;
  ll ret = 0;
  for (ll a=1ll; a*a*a<=n; a++) {
    for (ll b=a; a*b*b<=n; b++) {
      ll c = n/(a*b);
      ret+=(c-b+1);
    }
  }
  
  cout << ret << "\n";
  return 0;
}
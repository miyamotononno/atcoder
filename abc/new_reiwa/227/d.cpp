#include <bits/stdc++.h>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int k,n;

bool solve(const ll& val, const ll& k, ll a[]) {
  ll sum=0ll;
  rep(i, n) sum+=min(a[i], val);
  return sum >= val*k;
}

int main() {
  INCANT;
  cin >> n >> k;
  ll a[n];
  rep(i,n) cin >> a[i];
  
  ll ok=0ll;
  ll ng=2e18/k;
  while(ng-ok>1) {
    ll mid = (ok+ng)/2;
    if (solve(mid, k, a)) ok = mid;
    else ng = mid;
  } 
  cout << ok << endl;
  return 0;
}
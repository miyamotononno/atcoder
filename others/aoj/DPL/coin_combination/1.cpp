#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll calc(ll a[], ll b[], ll c[], ll d[], const int& n, const ll& v) {
  unordered_map<ll, ll> ab;
  unordered_map<ll, ll> cd;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      ab[a[i]+b[j]]++;
    }
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cd[c[i]+d[j]]++;
    }
  }
  ll ret=0ll;
  for (auto p: ab) {
    ret+=p.second*cd[v-p.first];
  }
  return ret;
}
  

int main() {
  int n;
  ll v;
  cin >> n >> v;
  ll a[n], b[n], c[n], d[n];
  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=0; i<n; i++) cin >> b[i];
  for (int i=0; i<n; i++) cin >> c[i];
  for (int i=0; i<n; i++) cin >> d[i];
  cout << calc(a,b,c,d,n,v) << endl;
}
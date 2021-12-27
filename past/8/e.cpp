#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(const vector<ll>& P, const vector<int>& C, const int& k) {
  unordered_map<ll, int> U;
  for (int i=0; i<P.size(); i++) {
    ll p = P[i];
    int c = C[i];
    if (U[c]==0 || U[c] > p) {
      U[c] = p;
    }
  }
  if (U.size()<k) return -1;
  vector<ll> vec;
  for (auto p: U) {
    vec.push_back(p.second);
  }
  sort(vec.begin(), vec.end());
  ll ret = 0ll;
  for (int i=0; i<k; i++) {
    ret+=vec[i];
  }
  return ret;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> c(n);
  vector<ll>p(n);
  for (int i=0; i<n; i++) {
    cin >> c[i];
  }
  for (int i=0; i<n; i++) {
    cin >> p[i];
  }
  cout << solve(p, c, k) << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
distance関数
https://cpprefjp.github.io/reference/iterator/distance.html
*/

// [leftIdx, rightIdx)
void calc(int leftIdx, int rightIdx, ll a[], vector<ll> outVec[]) {
  int cnt = rightIdx - leftIdx;
  for (int i=0; i<(1<<cnt); i++) {
    ll t = 0ll;
    int idx=0;
    for (int bit=0; bit<cnt; bit++) {
      if ((1<<bit)&i) {
        t+=a[bit+leftIdx];
        idx++;
      }
    }
    outVec[idx].push_back(t);
  }
}

ll solve(ll a[], const int& n, const int& k, const ll& l, const ll& r) {
  if (k==1) {
    ll ret = 0ll;
    for (int i=0; i<n; i++) {
      if (a[i]>=l && a[i]<=r) ret++;
    }
    return ret;
  }
  int half = n/2;
  vector<ll> baseVec[half+1];
  calc(0, half, a, baseVec);
  vector<ll> targetVec[n-half+1];
  calc(half, n, a, targetVec);
  for (int i=0; i<=n-half; i++) {
    sort(targetVec[i].begin(), targetVec[i].end());
  }
  ll ret =0ll;
  for (int i=0; i<=half; i++) {
    if (i>k || k-i > n-half) continue;
    vector<ll> targetVals = targetVec[k-i];
    for (ll d: baseVec[i]) {
      auto itr = lower_bound(targetVals.begin(),targetVals.end(), l-d);
      auto itr2 = upper_bound(targetVals.begin(),targetVals.end(), r-d);
      ret += distance(itr, itr2);
    }
  }
  return ret;
}

int main() {
  int n,k;
  cin >> n >> k;
  ll L,R;
  cin >> L >> R;
  ll a[n];
  for (int i=0; i<n; i++) cin >> a[i];
  cout << solve(a,n,k,L,R) << endl;
}
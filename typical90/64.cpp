#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,Q;
ll A[100005];
int L[100005], R[100005];
ll V[100005];

int main() {
  cin >> N >> Q;
  for (int i=0; i<N; i++) cin >> A[i];
  vector<ll> ans(Q);
  vector<ll> diff(N-1);
  ll E=0ll;
  for (int i=1; i<N; i++) {
    E+=abs(A[i]-A[i-1]);
    diff[i] = A[i]-A[i-1]; // diff i means　diff between Mt. i and Mt.i-1
  }
  for (int i=0; i<Q; i++) {
    cin >> L[i] >> R[i] >> V[i];
    L[i]--;R[i]--;
    if (L[i]>0) {
      ll newDiff = diff[L[i]] + V[i]; // Mt 
      E = E - abs(diff[L[i]]) + abs(newDiff);
      diff[L[i]] = newDiff;
    }
    if (R[i]<N-1) {
      ll newDiff = diff[R[i]+1] - V[i];
      E = E - abs(diff[R[i]+1]) + abs(newDiff);
      diff[R[i]+1] = newDiff;
    }
    ans[i] = E;
  }
  for (int i=0; i<Q; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
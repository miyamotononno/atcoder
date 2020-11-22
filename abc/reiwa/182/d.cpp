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
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int n;
ll A[200003], Sum[200003], BigSum[200003];
int Idxes[200003]; // その回までで最高に進む時のidx

int main() {
  INCANT;
  cin >> n;
  rep(i, n) cin >> A[i];
  if (n==1) {
    cout << max(A[0], 0ll) << endl;
    return 0;
  }
  BigSum[0] = Sum[0] = A[0];
  Idxes[0] = A[0]>=0?0:-1;
  for (int i=1; i<n; i++) {
    Sum[i] = A[i]+Sum[i-1];
    if (Sum[Idxes[i-1]]<=Sum[i]) Idxes[i] = i;
    else Idxes[i] = Idxes[i-1];
  }
  for (int i=1; i<n; i++) BigSum[i] = Sum[i]+BigSum[i-1];

  if (Idxes[n-1]<0) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 0ll;
  rep(i, n-1) {
    if (Idxes[i+1]<0) continue;
    ans = max(ans, BigSum[i]+Sum[Idxes[i+1]]);
  }
  
  cout << ans << endl;
  return 0;
}
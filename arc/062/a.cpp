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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int N;
ll T[1001], A[1001];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N) cin >> T[i] >> A[i];

  ll cnt = T[0] + A[0];
  rep(i, N-1){
    if (T[i+1] == T[i] && A[i+1] == A[i]) continue;
    if (T[i+1] > T[i] && A[i+1] > A[i]){
      cnt = T[i+1] + A[i+1];
      continue;
    }
    ll s = max((A[i]+A[i+1] -1ll)/A[i+1], (T[i]+T[i+1] -1ll)/T[i+1]);
    cnt = s*(T[i+1]+A[i+1]);
    T[i+1] *=s;
    A[i+1] *=s; 
  }

  cout << cnt << "\n";
  return 0;
}

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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, T[100005], A[100005];
int K[100005]; // 確定している山の高さ

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> T[i];
  rep(i, N) cin >> A[i];
  if (T[N-1]!=A[0]) {
    cout << 0 << "\n";
    return 0;
  }
  K[0] = T[0];
  rep(i, N) {
    if (K[i]>0) continue;
    if (i==0) continue;
    if (T[i]-T[i-1]>0) K[i] = T[i];
  }
  K[N-1] = A[N-1];
  for (int i=N-2; i>=0; i--) {
    if (A[i]-A[i+1]>0) {
      if (T[i] < A[i]) {
        cout << 0 << "\n";
        return 0;
      }
      if (K[i] ==0) K[i] = A[i];
    }
  }
  ll ans=1ll;
  int left=0;
  int right=1;
  while(right<N) {
    if (K[right]>0) {
      ll tmp=1;
      rep(i, right-left-1) {
        tmp*=min(K[right], K[left]);
        tmp%=MOD;
      }
      ans*=tmp;
      ans%=MOD;
      left = right;
      right++;
    } else right++;
  }
  cout << ans << "\n";
  return 0;
}
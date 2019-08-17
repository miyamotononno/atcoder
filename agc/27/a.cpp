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
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
ll x;


int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> x;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  sort(A.begin(), A.end());
  ll cnt = 0ll;
  int ans = N-1;
  rep(i, N){
    cnt += A[i];
    if (x == cnt){
      ans = i+1;
      break;
    }
    if (x < cnt){
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
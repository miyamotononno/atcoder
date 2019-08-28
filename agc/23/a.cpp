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
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
ll A[200002];
ll B[200002];
unordered_map<ll, int> Mp;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N) cin >> A[i];
  int cnt = 0;
  B[0] = A[0];
  rep(i, N-1) B[i+1] = B[i]+A[i+1];
  rep(i, N) Mp[B[i]]++;
  ll ans = 0ll;
  for (auto it=Mp.begin(); it !=Mp.end(); ++it){
    ll v = it->first;
    ll cnt = it->second;
    if (v==0) ans+=cnt;
    ans+=cnt*(cnt-1)/2;
  }
  cout << ans << "\n";
  return 0;
}
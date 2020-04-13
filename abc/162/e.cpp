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
int N;
ll K;
ll Memo[100005]; // gcdがidxのときの場合の和
map<int, ll> M;

ll calc_npow(ll num) {
  ll tmp =1ll;
  rep(i, N) {
    tmp*=num;
    tmp%=MOD;
  }
  return tmp;
}

void init() {
  rep(i, K) M[K/(i+1)]=-1;
  for (auto p: M) M[p.first] = calc_npow(p.first);
} 

void calc(ll num) {
  ll cnt = M[K/num];
  ll idx=2ll;
  while(num*idx<=K) {
    cnt-=Memo[num*idx];
    cnt%=MOD;
    idx++;
  }
  if (cnt<0) cnt+=MOD;
  Memo[num] =cnt;
}

int main() {
  INCANT;
  cin >> N >> K;
  init();
  for(ll i=K; i>=1; i--) calc(i);
  ll ans =0ll;
  rep(i, K) {
    ans+=Memo[i+1]*ll(i+1);
    ans%=MOD;
  }
  if (ans<0) ans+=MOD;
  cout << ans << "\n";
  return 0;
}
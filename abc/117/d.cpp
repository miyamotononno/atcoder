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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const int INF = 2e9;
int N;
ll k, A[100005];

int main() {
  INCANT;
  cin >> N >> k;
  rep(i, N) cin >> A[i];

  ll ans=0ll;
  ll Cnt[40];
  rep(i, 40) {
    ll mask = 1ll << i;
    ll cnt = 0;
    rep(j, N) if (mask & A[j]) cnt++;
    Cnt[i] = cnt;
  }
  for (int i = 39; i>=-1; i--) { // XとKが初めて違うbitのところ。-1はX=K用
    if (i>=0 && !(k & (1ll<<i))) continue;
    ll tmp = 0ll;
    for (int bit=39; bit>=0; bit--) {
      ll mask = 1ll << bit;
      ll keisu = 0ll;
      if (i<bit) {
        if (k & mask) keisu = N-Cnt[bit];
        else keisu = Cnt[bit];
      }
      else if (i==bit) keisu=Cnt[bit];
      else keisu = max(Cnt[bit], N-Cnt[bit]);
      
      tmp+=keisu*mask; // pow(2, bit)としない！！
    }
    ans  = max(ans,tmp);
  }
  
  cout << ans <<  endl;
  return 0;
}

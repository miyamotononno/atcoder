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
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
map<ll, int> Mp;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  ll a;
  rep(i, N){
    cin >> a;
    Mp[a]++;
  }
  ll sm = 0ll;
  ll la = 0ll;
  ll ans = 0ll;
  for(auto p: Mp){
    if (p.second>=4){
        sm = p.first;
        la = p.first;
        ans=sm*la;
    } else if (p.second>=2){
      if (!la) la = p.first;
      else{
        sm = la;
        la = p.first;
        ans=sm*la;
      }
    }
  }


  cout << ans << "\n";
  return 0;
}
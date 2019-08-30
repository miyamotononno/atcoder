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
typedef pair<ll, pair<ll, ll> > P;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
ll A[100001];
ll B[100001];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  vector<P> C;
  ll a,b;
  rep(i, N){
    cin >> a >> b;
    P p = make_pair(a+b, make_pair(a, b));
    C.push_back(p);
  }
  sort(C.begin(), C.end(), greater<P>());
  ll ans = 0ll;
  rep(i, N){
    if (i%2==0){
      ans+=C[i].second.first;
    }else{
      ans-=C[i].second.second;
    }
  }
  cout << ans << "\n";
  return 0;
}
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
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
unordered_map<string, ll> M;
unordered_map<string, ll> A;
unordered_map<string, ll> R;
unordered_map<string, ll> C;
unordered_map<string, ll> H;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  string S;
  rep(i, N){
    cin >> S;
    char s = S[0];
    if (s == 'M') M[S]+=1ll;
    if (s == 'A') A[S]+=1ll;
    if (s == 'R') R[S]+=1ll;
    if (s == 'C') C[S]+=1ll;
    if (s == 'H') H[S]+=1ll;
  }
  ll m = M.size();
  ll a = A.size();
  ll r = R.size();
  ll c = C.size();
  ll h = H.size();
  ll ans = m*a*r+m*a*c+m*a*h+m*r*c+m*c*h+m*r*h;
  ans+=a*r*c+a*r*h+a*c*h+r*c*h;
  cout << ans << "\n";
  return 0;
}
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
int N, P;
string S;
int zyo10[200006];
int SmodP[200006];
unordered_map<int, ll> U;

void init() {
  int res = 1;
  rep(i, N) {
    zyo10[i] = res;
    res*=10;
    res%=P;
  }
}

int main() {
  INCANT;
  cin >> N >> P;
  cin >> S;
  if (P==2 || P==5) {
    ll ans = 0ll;
    rep(i, N) if ((S[i]-'0')%P==0) ans+=i+1;
    cout << ans << "\n";
    return 0;
  }
  init();
  SmodP[N-1] = (S[N-1]-'0')%P; 
  for(int i=N-1; i>=0; i--) {
    if (i==N-1) continue;
    int c = S[i] - '0';
    int keta = N-i-1;
    SmodP[i] = (zyo10[keta]*c+SmodP[i+1])%P;
  }
  rep(i, N) U[SmodP[i]]++;
  ll res=0ll;
  rep(i, P) {
    if (i==0) res+=U[i]*(U[i]+1)/2;
    else res+=U[i]*(U[i]-1)/2;
  }
  cout << res << "\n";
  return 0;
}
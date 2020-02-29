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
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
string S;
int cnt;
ll num;
ll ans;
ll l[500005], r[500005];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  int N=S.size();
  rep(i, N) {
    if (S[i]=='<')l[i+1] = l[i] +1; //左側に何個<が連続するか
  }
  for (int i=N-1;i>=0; i--) {
    if (S[i]=='>') r[i] = r[i+1]+1;
  }
  ll ans=0ll;
  rep(i, N+1) ans+=max(l[i], r[i]);
  cout << ans << "\n";
  return 0;
}
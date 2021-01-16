#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n;
ll A[100003], B[100003];

int main() {
  INCANT;
  cin >> n;
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  ll r = 0ll;
  rep(i,n) r+=A[i]*B[i];
  
  string ans = r==0?"Yes":"No";
  cout << ans << "\n";
  return 0;
}
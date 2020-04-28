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
int N;
typedef pair<ll, ll> P;

int main() {
  INCANT;
  cin >> N;
  ll a, b;
  vector<P> A,B;
  rep(i, N) {
    cin >> a >> b;
    if (b-a>=0) A.push_back(P(a,b));
    else B.push_back(P(b,a));
  }
  sort(ALL(A));
  sort(ALL(B), greater<P>() );

  ll ans = 0;
  ll sm = 0; 
  rep(i, A.size()) {
    ans = max(ans, sm+A[i].first);
    sm+= A[i].first-A[i].second;
  }
  rep(i, B.size()) {
    ans = max(ans, sm+B[i].second);
    sm-= B[i].first-B[i].second; 
  }
  cout << ans << endl;
  return 0;
}
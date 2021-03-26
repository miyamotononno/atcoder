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
ll A[300005], S[300005];

// Ai^2 - 2*Ai*Aj + Aj^2
// sum(i=2 to n) sum(j=1 to j=i-1) 2*(Ai*Aj)
// = 2*sum(i=2 to n) {Ai*A1+Ai*A2+...+Ai*A(i-1)}
// = 2*sum(i=2 to n) Ai (A1+A2+...+A(i-1))

int main() {
  INCANT;
  cin >> n;
  rep(i, n) {
    cin >> A[i];
    S[i+1] = S[i]+A[i];
  }
  ll d = 0ll;
  rep(i, n) {
    d+=A[i]*A[i];
  }
  d*=ll(n-1);
  for (int i=1; i<n; i++) {
    d -= 2*A[i]*S[i];
  }

  cout << d << "\n";
  return 0;
}
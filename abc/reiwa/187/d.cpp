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
ll A[200005];

int main() {
  INCANT;
  cin >> n;
  ll aoki = 0;
  ll a, b;
  rep(i,n) {
    cin >> a >> b;
    aoki += a;
    A[i] = 2*a+b;
  }
  sort(A, A+n, greater<ll>());
  rep(i, n) {
    aoki -= A[i];
    if (aoki<0) {
      cout << i+1 << endl;
      return 0;
    } 
  }
  return 0;
}
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <cmath>
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
ll n;

ll get_maruta(ll x) {
  double _t =sqrt(2*x);
  ll t = _t;
  if (2*x>=t*(t+1)) return t;
  return t-1;
} 
int main() {
  INCANT;
  cin >> n;
  if (n==1) {
    cout << 1 << endl;
    return 0;
  } 
  ll g = get_maruta(n+1);
  cout << n-g+1 << endl;
  return 0;
}
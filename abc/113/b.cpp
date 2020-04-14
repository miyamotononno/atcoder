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
int N, T, A;
double H[1001];

int main() {
  INCANT;
  cin >> N >> T >> A;
  rep(i, N) cin >> H[i];
  double d = T-A;
  double mn = 1000000.0;
  int ans=0;
  rep(i, N) {
    if (mn>abs(d-H[i]*0.006)) {
      mn = abs(d-H[i]*0.006);
      ans = i+1;
    }
  }
  
  cout << ans << "\n";
  return 0;
}
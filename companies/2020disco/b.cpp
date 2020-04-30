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
const ll INF = 1e18;
int N;
ll a[200005], SUM[200005];

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> a[i];
  SUM[0] = a[0];
  rep(i, N) {
    if (i==0) continue;
    SUM[i] = SUM[i-1]+a[i];
  }
  ll MIN = INF;
  rep(i, N) {
    MIN = min(MIN, abs(SUM[N-1]-2*SUM[i]));
  }
  cout << MIN << "\n";
  return 0;
}
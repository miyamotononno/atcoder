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
typedef long long ll;
using namespace std;
ll a,b,c,d;

int main() {
  INCANT;
  cin >> a >> b >> c >> d;
  ll ans = max(a*c, b*d);
  ll ans2 = max(a*d, b*c);
  cout << max(ans, ans2) << "\n";
  return 0;
}
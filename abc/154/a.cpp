#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
string s,t, u;
int a,b;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s>>t;
  cin >> a >> b;
  cin >> u;
  if (s==u) {
    cout << a-1 << ' ' << b << "\n";
  } else {
    cout << a << ' ' << b-1 << "\n";
  }

  return 0;
}
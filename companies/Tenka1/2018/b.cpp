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
int a,b,k;

void dfs(int cnt) {
  if (cnt==k) return;
  if (cnt%2==0) {
    if (a%2) a--;
    a/=2;
    b+=a;
  } else {
    if (b%2) b--;
    b/=2;
    a+=b;
  }
  dfs(cnt+1);
}

int main() {
  INCANT;
  cin >> a >> b >> k;
  dfs(0);

  cout << a << ' ' << b << "\n";
  return 0;
}
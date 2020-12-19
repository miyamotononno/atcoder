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

int main() {
  INCANT;
  cin >> n;
  int ans = 0;
  for (int i=1; i<=n; i++) {
    int tmp = i;
    bool ng =false;
    while(tmp>=10) {
      if (tmp%10==7) ng=true;
      tmp/=10;
    }
    if (tmp%10==7) ng=true;
    tmp = i;
    while(tmp>=8) {
      if (tmp%8==7) ng=true;
      tmp/=8;
    }
    if (tmp%10==7) ng=true;
    ans = ng?ans:ans+1;
  }
  cout << ans << endl;
  return 0;
}
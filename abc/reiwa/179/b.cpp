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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;

int main() {
  INCANT;
  cin >> N;
  int d1,d2;
  int cnt = 0;
  bool flag = false;
  rep(i, N) {
    cin >> d1 >> d2;
    if(d1==d2) {
      cnt++;
      if (cnt>=3) flag = true;
    } else cnt=0;
  }
  string ans = flag?"Yes":"No";
  cout << ans << "\n";
  return 0;
}
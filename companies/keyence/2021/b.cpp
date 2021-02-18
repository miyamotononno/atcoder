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
int N, K;
int cnts[300005];

int main() {
  INCANT;
  cin >> N >> K;
  int a;
  rep(i, N) {
    cin >> a;
    cnts[a]++;
  }
  int boxSize = K;
  int ans = 0;
  rep(i, 300001) {
    // cnts[i]<boxSizeの場合、boxSize[i]-a[i]個がiとなる。
    ans+=max(0, boxSize-cnts[i])*i;
    boxSize = min(boxSize, cnts[i]);
  }
  cout << ans << endl;
  return 0;
}
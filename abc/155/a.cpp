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
#include <set>
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int A, B, C;
set<int> T;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B>> C;
  T.insert(A);
  T.insert(B);
  T.insert(C);
  string ans = T.size() == 2?"Yes":"No";
  cout << ans<< "\n";
  return 0;
}
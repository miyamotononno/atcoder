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
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, M, p, wa_cnt;
bool AC[100003];
int WA[100003];
string s;
set<int> S;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M; 
  rep(i, M) {
    cin >> p >> s;
    p--;
    if (s == "AC") {
      S.insert(p);
      if (!AC[p]) wa_cnt+=WA[p];
      AC[p] = true;
    }
    else {
      WA[p]++;
    }
  }
  cout << S.size() << ' ' << wa_cnt << "\n";
  return 0;
}
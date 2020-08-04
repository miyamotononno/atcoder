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
int N;
int ans[4];
string label[4] = {"AC x ", "WA x ", "TLE x ", "RE x "};

int main() {
  INCANT;
  cin >> N;
  string s;
  rep(i, N) {
    cin >> s;
    if (s[0]=='A') ans[0]++;
    if (s[0]=='W') ans[1]++;
    if (s[0]=='T') ans[2]++;
    if (s[0]=='R') ans[3]++;
  }
  
  rep(i, 4) {
    cout << label[i] << ans[i] << endl;
  }
  return 0;
}
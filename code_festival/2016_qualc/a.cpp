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
string S;

int main() {
  INCANT;
  cin >> S;
  bool flag1=false;
  bool flag2=false;
  rep(i, S.size()) {
    if (S[i]=='C') flag1 = true;
    if (flag1 && S[i]=='F') flag2 = true;
  }
  string ans = flag1&&flag2?"Yes":"No";
  cout << ans << "\n";
  return 0;
}
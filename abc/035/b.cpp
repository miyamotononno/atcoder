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
int T;
string S;

int main() {
  INCANT;
  cin >> S >> T;
  int n = S.size();
  int hatena=0;
  int x=0,y=0;
  rep(i, n) {
    if (S[i]=='?') hatena++;
    if (S[i]=='L') x--;
    if (S[i]=='R') x++;
    if (S[i]=='U') y++;
    if (S[i]=='D') y--;
  }
  x=abs(x);
  y=abs(y);
  if (T==1) {
    cout << x+y+hatena << endl;
    return 0;
  }
  if (x+y>=hatena) {
    cout << x+y-hatena << endl;
    return 0;
  }
  if ((x+y)%2==hatena%2) cout << 0;
  else cout << 1;
  cout << "\n";
  return 0;
}
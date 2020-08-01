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
string s, t;

int main() {
  INCANT;
  cin >> s >> t;
  if (s[0]==t[0] && s[1]==t[1] && s[2]==t[2]) {
    cout << "same" << "\n";
    return 0;
  }
  rep(i, 3) {
    if (toupper(s[i])!=toupper(t[i])) {
      cout << "different" << endl;
      return 0;
    }
  }

  cout << "case-insensitive" << endl;
  return 0;
}
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
string s;

int main() {
  INCANT;
  cin >> s;
  if (s=="keyence") {
    cout << "YES" << endl;
    return 0;
  }
  n = s.size();
  rep(i, n-1) {
    for (int j=i+1; j<=n; j++) {
      // iからj番目を省略する
      string temp = s.substr(0, i);
      if (j<n) {
        temp+=s.substr(j);
      }
      if (temp=="keyence") {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << "\n";
  return 0;
}
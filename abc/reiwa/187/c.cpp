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
vector<string> A;
unordered_map<string, bool> U; // trueは!, falseはなし

int main() {
  INCANT;
  cin >> n;
  string s;
  rep(i, n) {
    cin >> s;
    if (s[0]=='!') {
      string t = s.substr(1);
      U[t] = true;
    } else {
      A.push_back(s);
    }
  }
  for (auto a: A) {
    if (U[a]) {
      cout << a << endl;
      return 0;
    }
  }
  cout << "satisfiable" << "\n";
  return 0;
}
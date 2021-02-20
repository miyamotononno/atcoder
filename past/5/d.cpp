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
vector<string> T;

bool comp(const string& x, const string& y) {
  int szx = x.size();
  int szy = y.size();

  rep(i, x.size()) {
    if (x[i]!='0') break;
    szx--;
  }

  rep(i, y.size()) {
    if (y[i]!='0') break;
    szy--;
  }

  // 文字列の長さで比較
  if (szy>szx) return true;
  if (szy<szx) return false;

  string ny = y.substr(y.size()-szy);
  string nx = x.substr(x.size()-szx);

  // 文字列で比較
  if (ny>nx) return true;
  if (ny<nx) return false;

  return y.size()-szy < x.size()-szx; // 0の数が小さい方がtrue
}

int main() {
  INCANT;
  cin >> n;
  string s;
  rep(i, n) {
    cin >> s;
    T.push_back(s);
  }
  sort(ALL(T), comp);
  rep(i, n) {
    cout << T[i] << endl;
  }
  
  
  return 0;
}
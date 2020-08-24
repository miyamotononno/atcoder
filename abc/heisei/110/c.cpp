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
string S, T;
vector<int> dict1[26], dict2[26];

int main() {
  INCANT;
  cin >> S >> T;
  int n = S.size();
  rep(i, n) {
    int s = S[i]-'a';
    int t = T[i]-'a';
    dict1[s].push_back(i);
    dict2[t].push_back(i);
  }

  // i番目の要素に等しいindexの集合がSとTについて同じ
  rep(i, 26) {
    vector<int> svec = dict1[i];
    int sz = svec.size();
    bool ng;
    rep(j, 26) {
      ng = true;
      bool tmp_ok = true;
      vector<int> tvec = dict2[j];
      int tz = tvec.size();
      if (sz!=tz) {
        tmp_ok = false;
        continue;
      }
      rep(k, sz) {
        if (svec[k]!=tvec[k]) {
          tmp_ok = false;
          continue;
        }
      }
      if (tmp_ok) {
        ng = false;
        break;
      }
    }
    if (ng) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << "\n";

  return 0;
}
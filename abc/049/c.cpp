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
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
string S;
string d[4] = {"maerd", "remaerd", "esare", "resare"};

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  string T = "";
  rep_down(i, S.size()){
    T.push_back(S[i]);
  }
  bool flag = true;
  while(flag){
    if (!T.size()) break;
    rep(i, 4){
      string s = d[i];
      flag = true;
      rep(j, s.size()){
        if (T[j] != s[j]){
          flag = false;
          break;
        }
      }
      if (flag){
        T = T.substr(s.size());
        break;
      }
    }
    if (!flag) {
      cout << "NO" << "\n";
      return 0;
    }
  }

  cout << "YES" << "\n";
  return 0;
}
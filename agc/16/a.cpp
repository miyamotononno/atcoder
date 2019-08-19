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
#include <stack>
#include <set>
#include <unordered_map>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const int INF = 1000000007;
string S;
unordered_map<char, int> M;

bool check(string s, char c) {
  bool is_end = true;
  for (auto x : s) if (x != c) is_end = false;
  return is_end;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  rep(i, S.size()){
    M[S[i]] += 1;
  }

  int ans = INF;

  for (auto it=M.begin(); it !=M.end(); ++it){
    char c = it -> first;
    string T = S;
    rep(i, S.size()){
      if (check(T, c)) {
        ans = min(i, ans);
        break;
      }
      string _t = "";
      rep(j, T.size()-1){
        if (T[j] == c || T[j + 1] == c) _t += c;
        else _t += T[j];
      }
      T = _t;
    }
  }
  cout << ans << endl;
  return 0;
}
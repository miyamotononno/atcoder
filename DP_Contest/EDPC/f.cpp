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
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
typedef long long ll;
using namespace std;
string s, t;
int DP[3003][3003]; //DP[i][j]はsのi文字目までと、tのj文字目までの部分文字列の長さ

// ① DP[i+1][j+1]を求めるために、DP[i][j],DP[i][j+1],DP[i+1][j]をどう使うか。
// その漸化式を求めてからDP[s.size()][t.size()]を求める
// ② それを求めてから、その最長文字列がなんであるのかを求める。
// DP[i][j]とDP[i-1][j-1],DP[i][j-1],DP[i-1][j]が変化する時がポイント 

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s >> t;
  rep(i, s.size()) {
    rep(j, t.size()) {
      if (s[i] == t[j]){ // 等しければDP[i][j]までの最長文字列にその文字を加えればいい
        DP[i+1][j+1] = max(DP[i+1][j+1], DP[i][j]+1);
      } else {
        // 等しくなければ、DP[i+1][j]までの最長文字列かDP[i][j+1]までの最長文字列
        DP[i+1][j+1] = max(DP[i+1][j], DP[i][j+1]);
      }
    }
  }

  string ans = "";
  int i = s.size();
  int j = t.size();
  while(i>0 && j>0) {
    if (DP[i][j] == DP[i-1][j]){
      i--;
      continue;
    }

    if (DP[i][j] == DP[i][j-1]){
      j--;
      continue;
    }

    ans = s[i-1] + ans;
    i--, j--;
  }

  cout << ans << endl;
}
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
string s;
vector<int> oper[2];
int x,y;
int x_cnt, y_cnt;
int dp[2][4002][16002];

bool dfsx(int idx, int cx, bool flag) {
  if (dp[0][idx][cx]>=0) return dp[0][idx][cx];
  if (idx==oper[0].size()) return cx==x+8001;
  bool ret = dfsx(idx+1, cx+oper[0][idx], true);
  if (flag) ret |= dfsx(idx+1, cx-oper[0][idx],true);
  dp[0][idx][cx] = ret;
  return ret;
}

bool dfsy(int idx, int cy) {
  if (dp[1][idx][cy]>=0) return dp[1][idx][cy];
  if (idx==oper[1].size()) return cy==y+8001;
  bool ret = dfsy(idx+1, cy+oper[1][idx]) || dfsy(idx+1, cy-oper[1][idx]);
  dp[1][idx][cy] = ret;
  return ret;
}


int main() {
  cin >> s;
  cin >> x >> y;
  int cnt=0;
  bool flag=false;
  bool xdir=false;
  rep(i, (int)s.size()) {
    if (i==0 && s[i]=='T') xdir=true;
    if (s[i]=='F') cnt++;
    else {
      if (cnt) oper[flag].push_back(cnt);
      flag = !flag;
      cnt=0;
    }
  }

  if (cnt) oper[flag].push_back(cnt);
  rep(k, 2) rep(i, 4002) rep(j, 16002) dp[k][i][j] = -1;
  string ans = dfsx(0, 8001, xdir) & dfsy(0, 8001)?"Yes":"No";
  cout << ans << endl;
  return 0;
}


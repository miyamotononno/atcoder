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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int H, W;
int r,c;
typedef pair<int, int> P;
int dh[4] = {1,0,-1,0}, dw[4] = {0, 1, 0, -1};

void calc(vector<vector<char> >& s, vector<vector<char> >& t) {
  queue<P> que;
  que.push(P(r, c));
  while(!que.empty()) {
    P p = que.front(); que.pop();
    int h = p.first;
    int w = p.second;
    if (t[h][w]!='-') continue;
    t[h][w] = 'o';
    rep(i, 4) {
      int nh = h + dh[i];
      int nw = w + dw[i];
      if ((nh<0) || (nh>=H) || (nw<0) || (nw>=W)) continue;
      if (t[nh][nw]!='-') continue;
      if (i==0) { // 下
        if (s[nh][nw]=='^') que.push(P(nh,nw));
      } else if (i==1) { // 右
        if (s[nh][nw]=='<') que.push(P(nh,nw));
      } else if (i==2) { // 上
        if (s[nh][nw]=='v') que.push(P(nh,nw));
      } else { // 左
        if (s[nh][nw]=='>') que.push(P(nh,nw));
      }
      if (s[nh][nw]=='.') que.push(P(nh,nw));
    }
  }
  rep(i, H) {
    rep(j, W) {
      if (t[i][j]=='-') t[i][j]='x';
    }
  }
}


int main() {
  INCANT;
  cin >> H >> W;
  vector<vector<char> > s(H, vector<char>(W));
  cin >> r >> c;
  r--;c--;
  rep(i, H) {
    rep(j, W) {
      cin >> s[i][j];
    }
  }
  vector<vector<char> > t(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      if (s[i][j]=='#') t[i][j]='#';
      else t[i][j]='-';
    }
  }
  calc(s, t);
  rep(i, H) {
    rep(j, W) {
      cout << t[i][j];
    }
    cout << endl;
  }

  return 0;
}
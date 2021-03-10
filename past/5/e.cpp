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
int H, W;
char S[11][11], T[11][11];
int sh, sw, gh, gw; // Tのハンコの周りの余計な部分を取り除く

void remove_padding() {
  bool flag = false; 
  rep(i, H) {
    rep(j, W) {
      if (T[i][j]=='#') {
        flag = true;
        break;
      }
    }
    if (flag) break;
    sh++;
  }
  flag = false;
  for (int i=H-1; i>=0; i--) {
    rep(j, W) {
      if (T[i][j]=='#') {
        flag = true;
      }
    }
    if (flag) break;
    gh++;
  }
  flag = false;
  rep(j, W) {
    rep(i, H) {
      if (T[i][j]=='#') {
        flag = true;
        break;
      }
    }
    if (flag) break;
    sw++;
  }
  flag = false;
  for (int j=W-1; j>=0; j--) {
    rep(i, H) {
      if (T[i][j]=='#') {
        flag = true;
        break;
      }
    }
    if (flag) break;
    gw++;
  }
}

void show(vector<vector<char> >& T90, vector<vector<char> >& T180, vector<vector<char> >& T270) {
  for (int i=sh; i<H-gh; i++) {
    for (int j=sw; j<W-gw; j++) {
      cout << T[i][j];
    }
    cout << endl;
  }

  cout << "===============" << endl;

  rep(i, T90.size()) {
    rep(j, T90[0].size()) {
      cout << T90[i][j];
    }
    cout << endl;
  }

  cout << "===============" << endl;

  rep(i, T180.size()) {
    rep(j, T180[0].size()) {
      cout << T180[i][j];
    }
    cout << endl;
  }

  cout << "===============" << endl;

  rep(i, T270.size()) {
    rep(j, T270[0].size()) {
      cout << T270[i][j];
    }
    cout << endl;
  }
}

bool func(int& top, int& left, vector<vector<char> > R) {
  rep(i, R.size()) {
    rep(j, R[0].size()) {
      if (R[i][j]=='#' && S[i+top][j+left]=='#') {
        return false;
      }
    }
  }
  return true;
}

void rotate(int th, int tw, vector<vector<char> >& T0,vector<vector<char> >& T90, vector<vector<char> >& T180, vector<vector<char> >& T270) {
  // T90
  rep(i, th) { // 2
    rep(j, tw) { // 3
      T0[i].push_back(T[i+sh][j+sw]);
    }
  }
  rep(i, tw) {
    rep(j, th) {
      T90[i].push_back(T[th-j-1+sh][i+sw]);
    }
  }

  rep(i, th) { // 2
    rep(j, tw) { // 3
      T180[i].push_back(T[th-i-1+sh][tw-j-1+sw]);
    }
  }

  rep(i, tw) {
    rep(j, th) {
      T270[i].push_back(T[j+sh][tw-i-1+sw]);
    }
  }
}

int main() {
  INCANT;
  cin >> H >> W;
  rep(i, H) rep(j, W) cin >> S[i][j];
  rep(i, H) rep(j, W) cin >> T[i][j];
  remove_padding();
  int th = H-sh-gh;
  int tw = W-sw-gw;
  // Tを4方向に回転し、それぞれSの左上から右下になぞる
  vector<vector<char> > T0(th);
  vector<vector<char> > T90(tw);
  vector<vector<char> > T180(th);
  vector<vector<char> > T270(tw);
  rotate(th, tw, T0, T90, T180, T270);
  // show(T90, T180, T270);

  // normal Tの左上をどこに設定するか
  rep(i, H-th+1) {
    rep(j, W-tw+1) {
       if (func(i, j, T0)) {
         cout << "Yes" << endl;
         return 0;
       }
    }
  }

  // 90度回転
  if (W>=th & H>=tw) {
    rep(i, H-tw+1) { // T90は縦tw, 横th
      rep(j, W-th+1) {
        if (func(i, j, T90)) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  // 180度回転
  rep(i, H-th+1) {
    rep(j, W-tw+1) {
      if (func(i, j, T180)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  // 270度回転
  if (W>=th & H>=tw) {
    rep(i, H-tw+1) {
      rep(j, W-th+1) {
        if (func(i, j, T270)) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;


  return 0;
}
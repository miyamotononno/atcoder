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
int h,w,x,y;
int S[101][101];
queue<int> que;

int main() {
  INCANT;
  cin >> h >> w >> x  >> y;
  x--;y--;
  char c;
  rep(i, h) {
    rep(j, w) {
      cin >> c;
      S[i][j]=c;
    }
  }
  int up=1;
  int cnt=1;
  while(x-up>=0) {
    if (S[x-up][y]=='.') {
      cnt++;
      up++;
    }
    else break; 
  }
  up=-1;
  while(x-up<h) {
    if (S[x-up][y]=='.') {
      cnt++;
      up--;
    }
    else break; 
  }
  int left = 1;
  while(y-left>=0) {
    if (S[x][y-left]=='.') {
      cnt++;
      left++;
    } else break;
  }
  left = -1;
  while(y-left<w) {
    if (S[x][y-left]=='.') {
      cnt++;
      left--;
    } else break;
  }
  cout << cnt << endl;
  
  return 0;
}
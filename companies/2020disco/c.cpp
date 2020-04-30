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
int H, W, K;
char s[301][301];
int a[301][301];

void calc() {
  int idx = 1;
  rep(i, H) {
    queue<int> que;
    rep(j, W) {
      if (s[i][j]=='#') que.push(idx++);
    }
    if (que.empty()) continue;
    int tmp=que.front();
    rep(j, W) {
      if (s[i][j] == '#') {
        tmp = que.front();
        que.pop();
        a[i][j] = tmp;
      } else {
        a[i][j] = tmp;
      }
    }
  }
}

void calc2() {
  for (int i=1; i<H; i++) {
    if (a[i][0]==0) {
      rep(j, W) a[i][j] = a[i-1][j];
    }
  }
  for (int i=H-2; i>= 0; i--) {
    if (a[i][0]==0) {
      rep(j, W) a[i][j] = a[i+1][j];
    }
  }
}

int main() {
  INCANT;
  cin >> H >> W >> K;
  rep(i, H) rep(j, W) cin >> s[i][j];
  calc();
  calc2();
  rep(i, H) {
    rep(j, W) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}
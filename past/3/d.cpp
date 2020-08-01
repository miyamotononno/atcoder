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
int N;
char S[5][201];

bool tate_fill(char d[5][3], int m) {
  rep(i, 5) {
    if (d[i][m]=='.') return false;
  }
  return true;
}

bool yoko_fill(char d[5][3], int m) {
  rep(i, 3) {
    if (d[m][i]=='.') return false;
  }
  return true;
}

int trans(char d[5][3]) {
  if (tate_fill(d, 0)) { // 0,6,8
    if (!tate_fill(d, 2)) return 6;
    if (yoko_fill(d, 2)) return 8;
    return 0;
  }
  if (tate_fill(d, 1)) return 1;
  if (tate_fill(d, 2)) { // 3,4,7,9;
    if (!yoko_fill(d, 2)) return 7;
    if (!yoko_fill(d, 0)) return 4;
    if (d[1][0]=='#') return 9;
    return 3;
  }
  if (d[1][0]=='#') return 5;
  return 2;
}

int main() {
  INCANT;
  cin >> N;
  string s;
  rep(i, 5) {
    rep(j, 4*N+1) cin >> S[i][j];
  }

  rep(i, N) {
    char d[5][3];
    rep(j, 4) {
      if(j==0) continue;
      rep(k, 5) d[k][j-1] = S[k][4*i+j];
    }
    trans(d);
    cout << trans(d);
  }
  cout << endl;
  
  return 0;
}
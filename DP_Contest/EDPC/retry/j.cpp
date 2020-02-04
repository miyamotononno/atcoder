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
const ll MOD = 1e9+7LL;
const int INF = 1e9+7;
int N, a[303];
double DP[303][303][303]; // 皿にあるのが1,2,3この確率。

double dfs(int x, int y, int z) {
  if (x == 0 && y == 0 && z == 0) return 0.0;
  if (DP[x][y][z]>0) return DP[x][y][z]; 
  double ret = 0.0;
  if (x>0) ret += dfs(x-1,y,z) *x;
  if (y>0) ret += dfs(x+1,y-1,z) *y;
  if (z>0) ret += dfs(x,y+1,z-1) *z;
  ret += N;
  ret /= (double)(x+y+z);
  DP[x][y][z] = ret;
  return ret; 
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int x=0,y=0,z=0;
  rep(i, N) {
    cin >> a[i];
    if (a[i] == 1) x++;
    if (a[i] == 2) y++;
    if (a[i] == 3) z++;
  }
  cout << fixed << setprecision(10) << dfs(x,y,z) << "\n";
  return 0;
}
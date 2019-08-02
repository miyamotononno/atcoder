#include <cstring>
#include <algorithm>
#include <iostream>
#include <iomanip>
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
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
int N;
double A[303];
double DP[301][301][301]; //状態が3枚の個数, 2枚の個数, 1枚の個数. resは全て0にするまでのの期待値

double dfs(int i, int j, int k){
  if (DP[i][j][k] > 0) return DP[i][j][k];
  if (i==0 && j==0 && k==0) return 0.0;

  double ans = 0.0;
  if (i>0) ans += i*dfs(i-1, j+1, k);
  if (j>0) ans += j*dfs(i, j-1, k+1);
  if (k>0) ans += k*dfs(i, j, k-1);
  ans += N;
  ans /= (i+j+k);
  DP[i][j][k] = ans;
  return ans;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int i=0,j=0,k=0;
  int a;
  rep(n, N){
    cin >> a;
    if (a==3) i++;
    else if (a==2) j++;
    else if (a==1) k++;
  }
  double ans = dfs(i,j,k);
  cout << setprecision(10) << ans << endl;
  return 0;
}

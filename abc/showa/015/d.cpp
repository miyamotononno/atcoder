#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <utility>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <functional>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
using namespace std;
int W,N,K;
int A[50], B[50];
int dp[10100][60][60];

int dfs(int i, int j, int k){
  if(dp[i][j][k]>0) return dp[i][j][k];

  if (k<0) return 0;
  if ((i - A[k]<=0) || (j==0)) return dfs(i,j,k-1);
  int ans = max(dfs(i,j,k-1), dfs(i-A[k],j-1,k-1)+B[k]); //k番目のスクショを選ぶか選ばないか
  dp[i][j][k] = ans;
  return ans;
}

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> W >> N >> K;
  rep(i,N) cin >> A[i] >> B[i];

  int ans = dfs(W+1, K, N-1);
  cout << ans << endl; 
  return 0;
}
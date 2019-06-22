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
int D,N;
int T[210],A[210],B[210],C[210];
int dp[210][210];

int dfs(int i, int j){ // i日目 ,jは翌日にきた服のindex
    if (dp[i][j] > 0) return dp[i][j];
    int ans = 0;
    rep(n, N){
        if ((T[i]<A[n]) || (T[i]>B[n])) continue; 

        if(i==0) ans = max(ans, abs(C[n] - C[j]));
        else if(i==D-1) ans = max(ans, dfs(i-1, n));
        else ans = max(ans, dfs(i-1, n) + abs(C[n] - C[j]));
    }
    if(i<D) dp[i][j] = ans;
    return ans;
}

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> D >> N;
  rep(i,D) cin >> T[i];
  rep(i,N) cin >> A[i] >> B[i] >> C[i]; 

  int ans = dfs(D-1, 0);
  cout << ans << endl;

  return 0;
}
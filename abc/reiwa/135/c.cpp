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
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
int N;
ll A[100005], B[100005];

ll dfs(int cnt, ll pre){
  if (cnt == N+1) return 0;
  ll sm = 0;
  if (A[cnt] <= pre){ //一つ前の勇者で全て倒せた
    sm+= A[cnt];
    sm += dfs(cnt+1, B[cnt]); // 前の勇者は送らない
    return sm;
  }else { //一つ前の勇者をすべて使い、今の勇者も必要
    sm += pre;
    A[cnt]-=pre;
    if (A[cnt] <= B[cnt]){ // 今の勇者で全て倒せた
      sm+=A[cnt];
      sm += dfs(cnt+1, B[cnt]-A[cnt]);
    }else{ // 全ては倒せなかった
      sm += B[cnt];
      sm += dfs(cnt+1, 0);
    }
    return sm;
  }
  
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N+1) cin >> A[i];
  rep(i, N) cin >> B[i];

  ll ans = dfs(0, 0);
  cout << ans << endl;
  return 0;
}
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
int N, K;
int A[101];
int DP[100003][2]; //残りの山の数, そのとき先手(0)か後手(1)か. 未捜査(-1)か先手が勝つ(0)か後手が勝つ(1)か

// 残りの石のうち、どれかが相手を負けにすることができることならば、自分の勝ちとする。
int dfs(int rest, int turn){
  if (DP[rest][turn] > -1) return DP[rest][turn]; 
  int next = (turn+1)%2;
  int ans = next;
  rep(i, N){
    if (rest - A[i] >= 0){
      int flag = dfs(rest - A[i], next);
      if (flag == turn){
        ans = turn;
        break;
      }
    }
  }
  DP[rest][turn] = ans;
  return ans;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  rep(i, N){
    cin >> A[i];
  }

  rep(i, K+1) {
    DP[i][0] = -1;
    DP[i][1] = -1;
  }

  DP[0][0] = 1;
  DP[0][1] = 0;

  string ans = (dfs(K, 0)==0)?"First":"Second";
  cout << ans << endl;
  return 0;
}

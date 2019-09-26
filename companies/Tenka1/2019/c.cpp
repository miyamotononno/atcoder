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
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
string S;
int W[200002];
int B[200002];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  cin >> S;

  W[0] = S[0]=='.'?1:0;
  rep(i, N-1){
    if (S[i+1]=='.') W[i+1]=W[i]+1;
    else W[i+1]=W[i];
  }
  B[N-1] = S[N-1]=='#'?1:0;
  rep_down(i, N-1){
    if (S[i]=='#') B[i]=B[i+1]+1;
    else B[i]=B[i+1];
  }
  int ans = N - B[0];
  rep(i, N){
    if (i==N-1){
      ans = min(ans, N - W[N-1]);
      break;
    }
    ans = min(ans, N-W[i]-B[i+1]);
  }

  cout << ans << "\n";
  return 0;
}
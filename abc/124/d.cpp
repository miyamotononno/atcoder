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
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N, K;
string S;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  cin >> S;

  vector<int> M;
  bool isInitialHandStand = S[0]=='1';
  bool isLastHandStand = S[N-1]=='1';
  bool isHandStand = isInitialHandStand;
  int cnt = 0;

  // 最初直立→最初0人が逆立ちしていると考える
  // 最後直立→最後0人が逆立ちしていると考える
  if (!isInitialHandStand) {
    M.push_back(cnt);
  }
  rep(i, N){
    char c = S[i];
    if ((c == '0' && isHandStand) || (c == '1' && !isHandStand)){
      M.push_back(cnt);
      isHandStand = !isHandStand;
      cnt = 1;
    } else cnt++;
  }
  M.push_back(cnt);
  if (!isLastHandStand) {
    M.push_back(0);
  }

  int sz = (int)M.size();
  if (sz <= 2*K+1){
    cout << N << "\n";
    return 0;
  }

  vector<int> Sm(sz+1, 0); //計算のため, Sm[0] = 0とする
  Sm[0] = 0;
  rep(i, M.size()) Sm[i+1] = Sm[i] + M[i];
  
  int ans = 0;
  for (int idx=0; idx<sz-2*K; idx+=2) {
    ans = max(ans, Sm[idx+2*K+1]-Sm[idx]);
  }

  cout << ans  << "\n";
  return 0;
}
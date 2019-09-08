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
  int cnt = N;
  if (S[0]=='L') cnt--;
  if (S[N-1]=='R') cnt--;
  int idx = 1;
  rep(i, N){
    if (i<N-1 && S[i] == 'R' && S[i+1] == 'L') cnt--;
    if (i>0 && S[i] == 'L' && S[i-1] == 'R') cnt--;
  }
  cout << min(cnt+2*K, N-1) << "\n";
  return 0;
}
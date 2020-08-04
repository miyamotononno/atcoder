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
int N;
int A[21], B[21], C[21];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  rep(i, N-1) cin >> C[i+1];
  int ans = 0;
  int tmp = -10;
  rep(i, N){
    int a = A[i];
    a--;
    ans+=B[a];
    if (a==tmp+1) ans+=C[a];
    tmp = a;
  }

  cout << ans << "\n";
  return 0;
}
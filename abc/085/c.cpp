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
int N, Y;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> Y;
  int ans1 = -1;
  int ans2 = -1;
  int ans3 = -1;
  rep(i, N+1){
    rep(j, N+1){
      int k = N-i-j;
      if (1000*i+5000*j+10000*k==Y){
        if (k>=0){
          ans1=k;
          ans2=j;
          ans3=i;
          break;
        }
      }
    }
  }

  cout << ans1 << ' ' << ans2 << ' ' << ans3 << "\n";
  return 0;
}
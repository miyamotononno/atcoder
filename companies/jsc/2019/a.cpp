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
int M,D;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> M >> D;
  if (D<22 || M<4) {
    cout << 0 << "\n";
    return 0;
  };
  int d1=D%10;
  int d2=D/10;

  int ans=0;
  for(int i=4; i<=M; i++){
    for (int j=2; j<=d2-1; j++){
      for (int k=2; k<=9;k++){
        if (i==j*k) ans++;
      }
    }
    for (int k=2; k<=d1;k++){
      if (i==d2*k) ans++;
    }
  }

  cout << ans << "\n";
  return 0;
}
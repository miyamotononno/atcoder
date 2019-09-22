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
int H, W, A, B;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> H >> W >> A >> B;

  rep(i, B){
    rep(j, A) cout << 0;
    rep(j, W-A) cout << 1;
    cout << endl;
  }

  rep(i, H-B){
    rep(j, A) cout << 1;
    rep(j, W-A) cout << 0;
    cout << endl;
  }
  
  return 0;
}
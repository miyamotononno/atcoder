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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
int N;
int H[100005];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i,N) cin >> H[i];
  
  bool flag = true;
  bool checked = false;
  H[N] = 1e9;
  rep(i, N){
    if (H[i+1] - H[i] < -1){
      flag = false;
      break;
    };
    if (H[i+1] - H[i] == -1) {
      if (!checked){
        flag = false;
        break;
      } else checked = false;
    }
    if (H[i+1] - H[i] > 0) checked = true;
  }

  string ans = flag?"Yes":"No";

  cout << ans << endl;
  return 0;
}
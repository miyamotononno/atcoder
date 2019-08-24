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
typedef pair<int, int> P;
vector<P> U;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int a;
  rep(i, N){
    cin >> a;
    P p = make_pair(a,3);
    U.push_back(p);
  }
  rep(i, N){
    cin >> a;
    P p = make_pair(a,2);
    U.push_back(p);
  }
  rep(i, N){
    cin >> a;
    P p = make_pair(a,1);
    U.push_back(p);
  }
  sort(U.begin(), U.end(), greater<P>());

  ll ans = 0ll;
  ll b_c_cnt = 0ll;
  ll c_cnt = 0ll;
  rep(i, 3*N){
    int v = U[i].second;
    if (v ==3){
      ans+=b_c_cnt;
    }
    if (v == 2){
      b_c_cnt+=c_cnt;
    }
    if (v == 1){
      c_cnt++;
    }
  }
  
  cout << ans << "\n";
  
  return 0;
}
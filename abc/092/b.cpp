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
int N, D, X;
int A[101];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> D >> X;
  rep(i, N) cin >> A[i];

  int cnt = 0;
  rep(i, D){
    rep(j, N){
      if (i%A[j]==0) cnt++;
    }
  }
  cnt += X;

  cout << cnt << endl;
  return 0;
}
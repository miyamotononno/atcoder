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
int N;
ll x, A[100001];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> x;
  ll a;
  rep(i, N) cin >> A[i];
  
  ll cnt = 0ll;
  rep(i, N-1){
    ll sm = A[i]+A[i+1];
    if (sm <= x) continue;
    
    if (A[i+1] >= sm-x){
      A[i+1]-=(sm-x);
      cnt += (sm-x);
    } else {
      A[i] -= (sm - x - A[i+1]);
      A[i+1] = 0;
      cnt += sm -x;
    }
  }

  cout << cnt << "\n";
  return 0;
}
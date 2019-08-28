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
ll A[10001], B[10001];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  ll sm1 = 0ll;
  ll sm2 = 0ll;
  rep(i, N){
    cin >> A[i];
    sm1+=A[i];
  }
  rep(i, N){
    cin >> B[i];
    sm2+=B[i];
  }
  ll cnt = sm2-sm1;
  if (cnt <0){
    cout << "No" << "\n";
    return 0;
  }
  ll cnt1 = cnt;
  ll cnt2 = cnt;

  rep(i, N){
    ll diff = B[i] - A[i];
    if (diff > 0 && diff%2==0){
      cnt1-=diff/2;
      A[i] = B[i];
      continue;
    }
    if (diff > 0 && diff%2==1){
      cnt1-=(diff/2+1);
      cnt2-=1;
      A[i] = B[i];
      continue;
    }
    if (diff < 0){
      cnt2+=diff; // 負であることに注意
      A[i] = B[i];
    }
  }
  if (cnt1 < 0 || cnt2 < 0){
    cout << "No" << "\n";
    return 0;
  }
  if (cnt2 == 2*cnt1){
    cout << "Yes" << "\n";
    return 0;
  }

  cout << "No" << "\n";
  return 0;
}
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
int C[502];
int S[502];
int F[502];
int Ans[502];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N-1){
    cin >> C[i] >> S[i] >> F[i];
  }
  rep(i, N){
    int ans = 0;
    for (int j=i;j<N-1;j++){
      if (S[j] >= ans){
        ans= S[j];
      } else{
        int amari = ans%F[j];
        if (amari>0) ans+=F[j]-amari;
      }
      ans+=C[j];
    }
    cout << ans << "\n";
  }

  // cout << N << "\n";
  return 0;
}
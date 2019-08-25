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
ll A[100001];
ll B[100001];
ll D1[100001];
ll D2[100001];
ll D[100001];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N) cin >> A[i];
  B[0]=A[0];
  rep(i, N-1){
    B[i+1] = B[i] + A[i+1];
  }
  ll ans1 = 0ll;
  ll cnt = 0ll;
  rep(i, N){
    if (i%2==0){
      if (B[i]+cnt>0) continue;
      else{
        ans1+=1-(B[i]+cnt);
        cnt+=1-(B[i]+cnt); 
      }
    } else{
      if (B[i]+cnt<0) continue;
      else{
        ans1+=B[i]+cnt-(-1);
        cnt-=(B[i]+cnt-(-1));
      }
    }
  }
  ll ans2 =0ll;
  cnt = 0ll;
  rep(i, N){
    if (i%2==1){
      if (B[i]+cnt>0) continue;
      else{
        ans2+=1-(B[i]+cnt);
        cnt+=1-(B[i]+cnt); 
      }
    } else{
      if (B[i]+cnt<0) continue;
      else{
        ans2+=B[i]+cnt-(-1);
        cnt-=(B[i]+cnt-(-1));
      }
    }
  }

  cout << min(ans1,ans2) << "\n";
  return 0;
}
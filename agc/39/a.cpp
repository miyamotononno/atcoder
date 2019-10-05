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
int K;
string S;
typedef pair<ll, ll> P;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  cin >> K;

  ll cnt = 0ll;
  bool init_same=false;
  ll start_idx = -2ll;
  vector<P> vec;
  rep(i, S.size()-1){
    if (S[i]!=S[i+1]){
      vec.push_back(P(start_idx, cnt));
      if (start_idx==0) init_same = true;
      cnt = 0;
    } else {
      if (cnt==0) start_idx = i;
      cnt++;
    }
  }

  ll total = 0ll;
  // 最初と最後が違う場合
  if (S[0] != S[S.size()-1]){ // ex) s-------t
    vec.push_back(P(start_idx, cnt)); // cnt==0でもどうせ0が足されるので問題ない
    rep(i, vec.size()){
      total+=(vec[i].second+1)/2;
    }
    cout << total*K<< "\n";
    return 0;
  }

  // 全部同じ場合
  if (vec.size()==0){
    ll ans = (S.size()*K)/2;
    cout << ans << "\n";
    return 0;
  }

  // 最初と最後が同じだが、0番目と1番目が同じ
  if (init_same){
    ll real_init = vec[0].second;
    vec[0] = P(0, real_init+cnt+1);
    rep(i, vec.size()){
      if (i==0) total+=((vec[i].second+1)/2)*(K-1);
      else total+=((vec[i].second+1)/2)*K;
    }
    total+=(real_init+1)/2;
    total+=(cnt+1)/2;
    cout << total<< "\n";
    return 0;
  }

  // 最初と最後が同じだが、0番目と1番目が違う    
  // vec.push_back(P(S.size()-1, cnt+1));
  rep(i, vec.size()){
    total+=((vec[i].second+1)/2)*K;
  }
  total+=(cnt/2+1)*(K-1);
  total+=(cnt+1)/2;
  cout << total<< "\n";
  return 0;
}
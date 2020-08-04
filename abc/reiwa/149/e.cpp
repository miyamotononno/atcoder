#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
typedef pair<ll, ll> P;
const int INF = 2e9;
int N;
ll M, A[100002], SM[100002]; // sumはNコメからidx番目までの総和

// 価値X以上が選ばれるとした時に、idx番目の左手は何番目の右手とまで握手できるか
// 計算量O(log(N))
int calc1(int idx, ll X) {
  ll base = X-A[idx];
  return lower_bound(A, A+N, base)-A;
}

// 価値X以上が選ばれるとなった時に、全体で何個あるかと総和はいくらか
// 計算量O(N*log(N))
P calc2(ll X) {
  ll ret_cnt = 0ll;
  ll ret_sum = 0ll;
  for (int i=N-1; i>=0; i--) {
    int idx = calc1(i, X);
    if (idx==N) return P(ret_cnt, ret_sum);
    ret_cnt+= (N-idx);
    ret_sum+= (N-idx)*A[i]+SM[idx];
  }
  return P(ret_cnt, ret_sum);
}

// K番目のときの最小価値を求める。returnはそのときの総和
// 計算量O(log(A)*N*log(N))
ll calc3() {
  ll ng = 2*A[0], ok = 2*A[N-1];
  ll ret = 0ll;
  ll cnt = 0ll;
  while(ok-ng>1) {
    ll mid = (ok+ng)/2;
    P p = calc2(mid);
    cnt = p.first;
    ret = p.second;
    if (cnt<M) ok=mid; // 個数が少ないので基準を下げて緩くする
    else ng = mid; // 個数が多いので制限を基準をあげて厳しくする
  }
  return ret+(M-cnt)*ng; //　M-cnt個の価値ngを足すこと
}


int main() {
  INCANT;
  cin >> N >> M;
  rep(i, N) cin >> A[i];
  sort(A, A+N);
  SM[N-1] = A[N-1];
  for (int i=N-2; i>=0; i--) SM[i] = SM[i+1]+A[i];
  cout << calc3() << "\n";
  return 0;
}
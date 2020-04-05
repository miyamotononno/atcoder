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
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;
int N, Memo[200005]; // idx番目の座標+2*D版目以内の最大のidx
ll D, A, Sm[200005], Ans[200005];
P C[200005];

// 尺とりで前処理
void init() {
  int left = 0, right = 1;
  while(left<N) {
    if (C[right].first - C[left].first<=2*D) right++;
    else {
      Memo[left] = min(right-1, N-1);
      left++;
    }
  }
}

ll solve() {
  int left_bomb_idx = 0;
  ll ret = 0ll;
  rep(i, N) {
    ll requred_bomb = C[i].second;
    if (i==0) {
      Sm[0] = requred_bomb;
      Ans[0] = requred_bomb;
      ret+=requred_bomb;
      continue;
    }
    while (Memo[left_bomb_idx] < i) left_bomb_idx++;
    ll total_bomb_at_this = Sm[i-1]-(left_bomb_idx==0?0:Sm[left_bomb_idx-1]);
    Ans[i] = max(0ll, requred_bomb-total_bomb_at_this);
    ret+=Ans[i];
    Sm[i] = Ans[i] + Sm[i-1];
  }
  return ret;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> D >> A;
  ll x, h;
  rep(i, N) {
    cin >> x >> h;
    C[i] = P(x,(h+A-1)/A); // secondは何回の攻撃で死ぬか 
  }
  sort(C, C+N);
  init();
  cout << solve() << endl;
  return 0;
}
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <deque>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
string S;
vector<int> numToCnt(10);

ll dequeToLong(deque<ll> D) {
  ll val = 0ll;
  while(!D.empty()) {
    val *= 10ll;
    val += D.back();
    D.pop_back();
  }
  return val;
}

ll calc(deque<ll> A, deque<ll> B) {
  ll a_val, b_val;
  a_val = dequeToLong(A);
  b_val = dequeToLong(B);
  return a_val*b_val;
}

ll dfs(int idx, deque<ll> A, deque<ll> B, vector<int> rest) {
  if (idx==10) return calc(A, B);
  if (rest[idx]==0) return dfs(idx+1, A, B, rest);
  ll val = ll(idx);
  rest[idx]--;
  // aに追加
  A.push_back(val);
  ll a_val = dfs(idx, A, B, rest); 
  // 戻す
  A.pop_back();
  // bに追加
  B.push_back(val); 
  ll b_val = dfs(idx, A, B, rest);
  return max(a_val, b_val); 
}

int main() {
  INCANT;
  cin >> S;
  for (auto s: S) {
    numToCnt[s-'0']++;
  }
  ll a,b = 0;
  deque<ll> A, B;
  cout << dfs(0, A, B, numToCnt) << endl; 
  return 0;
}
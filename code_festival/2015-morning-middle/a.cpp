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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int N;
ll K, M, R, S[105];
priority_queue<ll> que;

int main() {
  INCANT;
  cin >> N >> K >> M >> R;
  rep(i, N-1) cin >> S[i];
  rep(i, N-1) que.push(S[i]);
  ll SUM=0;
  rep(i, K-1) {
    SUM+=que.top();
    que.pop();
  }
  
  if (SUM>=R*K) {
    cout << 0 << "\n";
    return 0;  
  }
  if (!que.empty()) {
    if (SUM+que.top()>=R*K) {
      cout << 0 << "\n";
      return 0;
    } 
  }

  if (SUM+M<R*K) {
    cout << -1 << "\n";
  } else {
    cout << R*K-SUM << "\n";
  }
  return 0;
}
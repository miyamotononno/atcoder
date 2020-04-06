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
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int X, Y, Z, K;
ll A[1001], B[1001], C[1001], D[3001];
priority_queue<ll> que;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> X >> Y >> Z >> K;
  rep(i, X) cin >> A[i];
  rep(i, Y) cin >> B[i];
  rep(i, Z) cin >> C[i];
  rep(i, X) rep(j, Y) que.push(A[i]+B[j]);
  rep(i,min(K, X*Y)) {
    ll p = que.top(); que.pop();
    D[i] = p;
  }
  while(!que.empty()) que.pop();
  rep(i, K) rep(j, Z) que.push(D[i]+C[j]);
  rep(i,K) {
    ll p = que.top(); que.pop();
    cout << p << "\n";
  }
  return 0;
}
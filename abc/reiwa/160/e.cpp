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
const int INF = 2e9;
int X, Y, A, B, C;
ll p[100004], q[100004], r[100004]; 
priority_queue<ll, vector<ll>, greater<ll>> que;

int main() {
  INCANT;
  cin >> X >> Y >> A >> B >> C;
  rep(i, A) cin >> p[i];
  rep(i, B) cin >> q[i];
  rep(i, C) cin >> r[i];
  sort(p, p+A);
  sort(q, q+B);
  sort(r, r+C, greater<ll>());
  ll sm=0ll;
  rep(i, X) {
    sm+=p[A-1-i];
    que.push(p[A-1-i]);
  }
  rep(i, Y) {
    sm+=q[B-1-i];
    que.push(q[B-1-i]);
  }
  ll q=que.top();
  int idx = 0;
  while(idx<C && !que.empty()) {
    q = que.top();
    if (r[idx]<=q) idx++;
    else {
      sm-=q;
      sm+=r[idx];
      idx++;
      que.pop();
    }
  }
  cout << sm << endl;
  return 0;
}
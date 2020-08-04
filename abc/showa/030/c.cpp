#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <cmath>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, M;
ll X, Y;
queue<ll> A, B;

ll next_a(ll now) {
  while(!A.empty()) {
    ll q = A.front();
    if (now > q) A.pop();
    else return q+X;
  }
  return -1;
}

ll next_b(ll now) {
  while(!B.empty()) {
    int q = B.front();
    if (now > q) B.pop();
    else return q+Y;
  }
  return -1;
}

int calc() {
  int res = 0;
  ll now = 0ll;
  while(true) {
    now = next_a(now);
    if (now<0) return res;
    now = next_b(now);
    if (now<0) return res;
    res++;
  }
  return res;
}

int main() {
  INCANT;
  cin >> N >> M;
  cin >> X >> Y;
  ll c;
  rep(i, N) {
    cin >> c;
    A.push(c);
  }
  rep(i, M) {
    cin >> c;
    B.push(c);
  }
  cout << calc() << "\n";
  return 0;
}
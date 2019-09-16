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
int N, M;
ll A[100002];
priority_queue<ll> que;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  ll a;
  rep(i, N){
    cin >> a;
    que.push(a);
  }

  rep(i, M) {
    ll q = que.top();
    que.pop();
    que.push(q/2);
  }
  ll sm = 0;
  rep(i, N){
    ll q = que.top();
    que.pop();
    sm += q;
  }


  cout << sm << "\n";
  return 0;
}
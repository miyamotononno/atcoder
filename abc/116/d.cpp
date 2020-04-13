#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <climits>
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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, K;
typedef pair<ll, int> P;
vector<P> A;
priority_queue<ll, vector<ll>, greater<ll> > que;
priority_queue<ll> rest;
ll ans;

void init() {
  unordered_map<int, int> U;
  rep(i, N) {
    if (U[A[i].second]==0) {
      U[A[i].second]++;
      if (que.size()<K) {
        ans+=A[i].first;
        que.push(A[i].first);
      } else rest.push(A[i].first);
    } else {
      rest.push(A[i].first);
    }
  }
}

int main() {
  INCANT;
  cin >> N >> K;
  int t;ll d; 
  rep(i, N) {
    cin >> t >> d;
    A.push_back(P(d,t));
  }
  sort(ALL(A), greater<P>());
  init();
  ll x = que.size();
  ans+=x*x;
  while(que.size()<K) {
    ll t = rest.top(); rest.pop();
    ans+=t;
    que.push(t);
  }
  ll prev =ans;
  for (ll i=x-1; i>=1; i--) {
    ll tmp = prev;
    ll r =rest.top(); rest.pop();
    ll q= que.top(); que.pop();
    que.push(r);
    tmp+=r-q;
    tmp+=pow(i,2)-pow(i+1,2);
    ans = max(ans, tmp);
    prev = tmp;
  }
  cout << ans << "\n";
  return 0;
}
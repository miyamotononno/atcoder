#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define rep(i,n) for (int i=0; i<n;++i)
#define repll(i,n) for (ll i=0; i<n;++i)
typedef long long ll;
using namespace std;
const ll INF = 1e17;
int n;
ll K;
int P[5001];
ll C[5001];

int main() {
  INCANT;
  cin >> n >> K;
  int a;
  rep(i, n) {
    cin >> a;
    P[i] = a-1;
  }
  rep(i, n) cin >> C[i]; 
  
  ll MAX=-INF;
  rep(i, n) {
    vector<ll> score;
    ll circle=0ll;
    int p = i;
    do {
      p = P[p];
      score.push_back(C[p]);
      circle+=C[p];
    } while (p!=i);
    ll score_size = score.size();
    ll t = 0ll;
    repll(j, min(K, score_size)) {
      t+=score[j];
      ll now = t;
      if (circle>0ll) {
        ll e = (K-j-1ll)/score_size;
        now+=circle*e;
      }
      MAX=max(now, MAX);
    }
  }
  cout << MAX << endl;
  return 0;
}

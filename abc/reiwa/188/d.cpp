#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
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
int N;
ll C;
typedef pair<int, ll> P;
vector<P> D;

int main() {
  INCANT;
  cin >> N >>  C;
  int a,b,c;
  rep(i, N) {
    cin >> a >> b >> c;
    D.push_back(P(a-1, c));
    D.push_back(P(b, -c)); // この次の日から支払い停止なので
  }
  sort(ALL(D));
  int start = 0;
  ll price=0;
  ll ans = 0ll;
  for (int i=0; i<D.size(); i++) {
    if (i==0) { // この日までは払わなくていい
      price = D[i].second;
      continue;
    }
    ll day = D[i].first - D[i-1].first;
    ans+=day*min(C, price);
    price += D[i].second;
  }
  
  cout << ans << "\n";
  return 0;
}
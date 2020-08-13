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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const int INF = 2e9;
int N, K;
typedef pair<int, ll> P;
vector<P> D[30];

int main() {
  INCANT;
  cin >> N >> K;
  int l2 = log2(K);
  vector<int> kouho;
  kouho.push_back(K);
  for (int i=l2; i>=0; i--) {
    if (1<<i & K) {
      int k = K ^ (1 << i); // iけた目以外はKと等しい。iけた目を0にする
      k |= (1 << i)-1; //　下のけたは全て1
      kouho.push_back(k);
    }
  } 
  int a,b;
  vector<P> X(N);
  rep(i, N) {
    cin >> a >> b;
    X[i] = P(a,b);
  }
  ll ans = 0ll;
  for(auto k: kouho) {
    ll sm = 0ll;
    for (auto x: X) {
      if ((k | x.first)==k) sm+=x.second;
    }
    ans = max(ans, sm);
  }
  cout << ans << endl;
  return 0;
}
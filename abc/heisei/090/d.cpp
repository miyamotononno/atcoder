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
ll N, K;

int main() {
  INCANT;
  cin >> N >> K;
  ll cnt=0ll;
  for (ll b=K+1; b<=N; b++) {
    ll tmp=0ll;
    ll syo=N/b;
    ll amari =N%b;
    tmp+=max(amari-K+1ll,0ll);
    tmp+=(b-K)*syo;
    cnt+=tmp;
    if (!K) cnt--;
  }

  cout << cnt << "\n";
  return 0;
}
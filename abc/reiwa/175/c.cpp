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
ll X, K, D;

int main() {
  INCANT;
  cin >> X >> K >> D;
  X=abs(X);
  ll r = K-X/D;
  if (r<=0ll) {
    cout << abs(X-K*D) << endl;
    return 0;
  }
  K-=X/D;
  X%=D;
  ll ret = K%2ll?D-X:X;
  cout << ret << endl;
  return 0;
}
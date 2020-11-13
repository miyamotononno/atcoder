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
typedef long long ll;
using namespace std;
ll X, Y, A, B;

int main() {
  INCANT;
  cin >> X >> Y >> A >> B;
  ll ret = 0ll;
  while(X*A<Y) {
    if (X>B/(A-1)) break;
    ret++;
    X*=A;
  }
  if (X+B>=Y){
    cout << ret << "\n";
    return 0;
  }
  ll cnt = (Y-1-X)/B;
  cout << ret+cnt << "\n";
  return 0;
}
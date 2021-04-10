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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
ll n;

int main() {
  INCANT;
  cin >> n;
  if (n<1e3) {
    cout << 0 << endl;
    return 0;
  }

  if (n<1e6) {
    cout << n+1-1e3 << endl;
    return 0;
  }

  ll ret = (1e6-1e3)*1;
  if (n<1e9) {
    ret+=(n+1-1e6)*2ll;
    cout << ret << endl;
    return 0;
  }
  ret+= (1e9-1e6)*2ll;
  if (n<1e12) {
    ret+=(n+1-1e9)*3ll;
    cout << ret << endl;
    return 0;
  }
  ret+= (1e12-1e9)*3ll;
  if (n<1e15) {
    ret+=(n+1-1e12)*4ll;
    cout << ret << endl;
    return 0;
  }
  ret+= (1e15-1e12)*4ll;
  ret+=5ll;
  cout << ret << endl;
  return 0;
}
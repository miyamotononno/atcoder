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
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
ll S;

int main() {

  cin >> S;

  ll x2 = 1;
  ll y2 = 1e9;

  ll x3 = S/y2 + 1;
  ll y3 = y2 - S%y2;
  if (x3==1e9+1 && y3==1e9) {
    x3 = 1e9;
    y3 = 0;
  }

  cout << 0 << ' ' << 0  << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << endl;
 }
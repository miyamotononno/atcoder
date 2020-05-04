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
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
ll X;
// a>bと仮定

ll MAX_A() {
  ll i = 1;
  while(pow(i,5)-pow(i-1, 5)<=X) i++;
  return i;
}

int main() {
  INCANT;
  cin >> X;
  ll _A = MAX_A();
  for (ll i=_A; i>=-_A; i--) {
    for (ll j=_A; j>=-_A; j--) {
      if (pow(i, 5)-pow(j, 5)==X) {
        cout << i << ' ' << j << "\n";
        return 0;
      }
    }
  }
  return 0;
}
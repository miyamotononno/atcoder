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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
ll r1, c1, r2, c2;

int main() {
  INCANT;
  cin >> r1 >> c1 >> r2 >> c2;
  if (r1==r2 && c1==c2) {
    cout << 0 << endl;
    return 0;
  }
  if (r1+c1 == r2+c2) {
    cout << 1 << "\n";
    return 0;
  }
  if (r1-c1 == r2-c2) {
    cout << 1 << "\n";
    return 0;
  }
  if (abs(r1-r2)+abs(c1-c2)<=3) {
    cout << 1 << "\n";
    return 0;
  }
  if (abs(c2-(c1+r1-r2))<=3) {
    cout << 2 << "\n";
    return 0;
  }
  
  if (abs(c2-(c1+r2-r1))<=3) {
    cout << 2 << "\n";
    return 0;
  }

  if ((r1+c1)%2==(r2+c2)%2) {
    cout << 2 << "\n";
    return 0;
  }
  cout << 3 << endl;
  return 0;
}
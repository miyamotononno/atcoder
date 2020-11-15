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
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;

int main() {
  double x,y;
  cin >> x >> y;
  if (y==0.0) {
    cout << "ERROR" << endl;
    return 0;
  }
  cout << fixed << setprecision(2) << floor(100*x/y)/100 << endl;
  return 0;
}
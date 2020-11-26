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
int c[4];

int main() {
  INCANT;
  rep(i, 4) cin >> c[i];
  sort(c, c+4);
  if (c[0]==1 && c[1]==4 && c[2]==7 && c[3]==9) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << "\n";
  return 0;
}
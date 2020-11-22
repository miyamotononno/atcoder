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
string s;
int D[3];

int main() {
  INCANT;
  cin >> s;
  int n = s.size();
  int d_sum = 0;
  for (auto c: s) {
    int d = c-'0';
    d_sum+=d;
    D[d%3]++;
  }
  d_sum%=3;
  if (d_sum==0) {
    cout << 0 << endl;
    return 0;
  }
  if (D[d_sum]>0 && n!=1) {
    cout << 1 << endl;
    return 0;
  }
  if (D[2*d_sum%3]>=2 && n!=2) {
    cout << 2 << endl;
    return 0;
  }
    
  cout << -1 << endl;
  return 0;
}
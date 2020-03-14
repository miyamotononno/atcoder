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
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
ll a,b,c;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> a >> b >> c;
  if (c<=a+b) {
    cout << "No" << "\n";
    return 0;
  }
  string ans = c*(c-2*a-2*b) +pow(max(a, b)-min(a,b),2) > 0?"Yes":"No";
  cout << ans << "\n";
  return 0;
}

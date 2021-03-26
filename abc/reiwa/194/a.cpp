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
int a,b;

int main() {
  INCANT;
  cin >> a >> b;
  if (a+b>=15 && b>=8) {
    cout << 1 << endl;
  } else if (a+b>=10 && b>=3) {
    cout << 2 << endl;
  } else if (a+b>=3) {
    cout << 3 << endl;
  } else {
    cout << 4 << "\n";
  }
  
  return 0;
}
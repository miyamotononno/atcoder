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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, K, M;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K >> M;
  int sm = 0;
  int a;
  rep(i, N-1) {
   cin >> a;
   sm+=a; 
  }
  int po = M*N-sm;
  if (po > K) {
    cout << -1 << "\n";
  } else if (po <= 0) {
    cout << 0 << "\n";
  } else {
    cout << po << "\n";
  }

  return 0;
}
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
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;

int prime_factor(int n) {
  int ret = 0; 
  for(int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      int d = n/i;
      if (d==i) ret++;
      else ret+=2;
    }
  }
  return ret;
}

int main() {
  INCANT;
  cin >> N;
  int ans = 0;
  for (int c=1; c<N; c++) {
    int ab = N-c;
    ans += prime_factor(ab);
  }
  cout << ans << "\n";
  return 0;
}
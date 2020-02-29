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
int N;
int A[200003];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int a;
  rep(i, N) {
    cin >> a;
    a--;
    A[i] = a;
  }
  int idx = 0;
  rep(i, N) {
    if (A[i]==idx) {
      idx++;
    }
  }
  int ans = idx==0?-1:N-idx;
  cout << ans << "\n";
  return 0;
}
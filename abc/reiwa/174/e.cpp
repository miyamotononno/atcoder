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
int N, K;
int A[200003];

bool is_large(int X) {
  int cnt=0;
  rep(i, N) {
    cnt+=(A[i]+X-1)/X-1;
  }
  return cnt > K;
}

int binary_search(int l, int r) {
  while(r-l>1) {
    int mid = (r+l)/2;
    if (is_large(mid)) l = mid;
    else r = mid;
  }
  return r;
}

int main() {
  INCANT;
  cin >> N >> K;
  rep(i, N) cin >>A[i];
  cout << binary_search(0, 1e9) << endl;

  return 0;
}
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
#include <stack>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, M;
int a[300005];
int top[100005];
int Ans[100005];

int bs(int x) { // 左の方が大きい
  int left = -1;
  int right = N;
  while(right-left>1) {
    int mid = (left+right)/2;
    if (top[mid]>=x) left = mid;
    else right = mid;
  }
  return right;
}

int main() {
  INCANT;
  cin >> N >> M;
  rep(i, M) cin >> a[i];
  fill(top, top+N+1, -1);
  rep(i, M) {
    int idx = bs(a[i]);
    top[idx] = a[i];
    int ans = idx==N?-1:idx+1;
    cout << ans << "\n";
  }
  return 0;
}
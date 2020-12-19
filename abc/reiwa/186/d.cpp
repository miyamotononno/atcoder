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
int n;
ll A[200005];
ll sum[200005];
ll sumsum[200005];
ll ans[200005];

int main() {
  INCANT;
  cin >> n;
  rep(i, n) {
    cin >> A[i];
  }
  sort(A, A+n);
  for (int i=0; i<n-1; i++) {
    if (i==0) sum[0] = A[1]-A[0];
    else sum[i] = sum[i-1]+A[i+1]-A[i];
  }
  rep(i, n-1) {
    if (i==0) sumsum[i]=sum[i];
    else {
      sumsum[i] = sumsum[i-1]+sum[i];
    }
  }
  rep(i, n-1) {
    if (i==0) ans[0] = sumsum[0];
    else {
      ans[i] = ans[i-1] + sum[i]*(i+1)-sumsum[i-1];
    }
  }
  
  cout << ans[n-2] << endl;
  return 0;
}
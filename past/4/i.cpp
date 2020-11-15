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
int n;
ll A[400005];
ll sum;

ll calcDiff(ll x) {
  ll other = sum-x;
  return abs(other-x);
}

int main() {
  INCANT;
  cin >> n;
  rep(i, n) {
    cin >> A[i];
    sum+=A[i];
    A[n+i] = A[i];
  }
  int idx = 0;
  ll X = 0ll;
  ll minDiff = sum;
  rep(left, n) { // 左端
    if (left>0) X-=A[left-1]; 
    int right = left+n;
    ll currentDiff = calcDiff(X);
    while(calcDiff(X+A[idx])<=currentDiff && idx < right) {
      X+=A[idx];
      currentDiff = calcDiff(X);
      idx++;
    }
    minDiff = min(minDiff, currentDiff);
  }
  cout << minDiff << endl;
  return 0;
}
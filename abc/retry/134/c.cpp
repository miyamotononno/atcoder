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
int n, A[200005];

int main() {
  INCANT;
  cin >> n;
  rep(i, n) cin >> A[i];
  int sumIdx=-1; int nextSumIdx=-1;
  rep(i, n) {
    if (i==0) sumIdx=i;
    else {
      if (nextSumIdx<0) nextSumIdx = i;
      else if (A[nextSumIdx]<A[i]) nextSumIdx=i;

      if (A[sumIdx]<A[nextSumIdx]) {
        swap(sumIdx, nextSumIdx);
      }
    }
  }

  rep(i, n) {
    if (i==sumIdx) cout << A[nextSumIdx] << endl;
    else cout << A[sumIdx] << endl;
  }
  return 0;
}
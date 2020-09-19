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
int N, A[300005];

int large(int s, int u) {
  return u-s+1;
}

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> A[i];
  int left = 0;
  bool ascending = true;
  int MAX=0;
  for (int idx=1; idx<N; idx++) {
    if (ascending && A[idx-1]<A[idx]) continue;
    if (!ascending && A[idx-1]>A[idx]) continue;
    if (!ascending) {
      MAX = max(MAX, large(left, idx-1));
      left = idx-1;
    }
    ascending = !ascending;
  }
  MAX = max(MAX, large(left, N-1));
  cout << MAX << endl;
  return 0;
}
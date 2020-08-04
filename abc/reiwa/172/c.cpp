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
int N, M;
ll K;
ll A[200001], B[200001];

int main() {
  INCANT;
  cin >> N >> M >> K;
  rep(i, N) cin >> A[i];
  rep(i, M) cin >> B[i];
  ll sm=0ll;
  int a_idx=0;
  int b_idx=0;
  rep(i, N) {
    if (K >= sm+A[i]) {
      sm+=A[i];
      a_idx++;
    } else break;
  }
  rep(i, M) {
    if (K >= sm+B[i]) {
      sm+=B[i];
      b_idx++;
    } else break;
  }
  int max_cnt = a_idx+b_idx;
  ll rest = K-sm;
  for (int i=a_idx-1; i>=0; i--) {
    rest+=A[i];
    while(b_idx<=M-1 && B[b_idx]<=rest) {
      rest-=B[b_idx];
      b_idx++;
    }
    max_cnt = max(max_cnt, i+b_idx);
  }
  cout << max_cnt << endl;
  return 0;
}
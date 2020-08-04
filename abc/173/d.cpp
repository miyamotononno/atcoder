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
ll A[200005];
ll B[200005];

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> A[i];
  sort(A, A+N, greater<int>());
  B[0] = A[0];
  rep(i, N) {
    if (i==0) continue;
    if (2*i-1 < N) {
      B[2*i-1] = A[i];
    } 
    if (2*i-2 < N) {
      B[2*i] = A[i];
    }
  }
  ll sum = 0ll;
  rep(i, N-1) sum+=B[i];
  cout << sum << endl;
  return 0;
}
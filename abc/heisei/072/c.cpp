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
int N, A[100005];

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> A[i];
  sort(A, A+N);
  int left = 0;
  int right = 0;
  int ans = 0;
  while(right<N) {
    if (A[right]<=A[left]+2) right++;
    else {
      ans = max(ans, right-left);
      left++;
    }
  }
  ans = max(ans, right-left);
  cout << ans << "\n";
  return 0;
}
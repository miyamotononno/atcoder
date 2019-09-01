#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  vector<int> A(N);
  rep(i, N) cin >> A[i];

  sort(A.begin(),A.end());

  int a = A[0];
  int c = a+2;
  int ans = 1;
  while(a<=A.back()){
    int dis = distance(A.begin(), upper_bound(ALL(A), c));
    int dis2 = distance(A.begin(), lower_bound(ALL(A), a));
    ans = max(ans, dis - dis2);
    a++; c++;
  }

  cout << ans << "\n";
  return 0;
}
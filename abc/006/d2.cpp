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
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const int INF = 1000000007;
int N;
int C[300005];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N) cin >> C[i];
  vector<int> A(N, INF);
  vector<int> id(N);
  rep(i, N){
    auto itr = lower_bound(ALL(A), C[i]);
    id[i] = itr - A.begin();
    A[id[i]] = C[i];
  }

  int mx = 0;
  rep(i, N){
    mx = max(mx, id[i]);
  }

  cout << N-mx-1 << "\n";
  return 0;
}
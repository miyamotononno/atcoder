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
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define index_of(as, x) distance(as.begin(), lower_bound(as.begin(), as.end(), x))
typedef long long ll;
using namespace std;
const int INF = 1000000007;
int N;
int C[30003];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N) cin >> C[i];
  vector<int> A(N, INF);
  vector<int> id(N);
  rep(i, N){
    id[i] = index_of(A, C[i]);
    A[id[i]] = C[i];
  }

  int mx = 0;
  rep(i, N){
    mx = max(mx, id[i]);
  }

  cout << N- mx -1 << endl;
  return 0;
}
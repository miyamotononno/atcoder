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
int B[101];
int A[101];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N-1) cin >> B[i];
  A[0] = B[0];
  A[N-1] = B[N-2];
  rep(i, N-2){
    A[i+1] = min(B[i], B[i+1]);
  }
  int sm = 0;
  rep(i, N) sm += A[i];
  
  cout << sm << "\n";
  return 0;
}
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
int N,K;
int A[200005], B[200005]; // 逆回り 

int main() {
  INCANT;
  cin >> K >> N;
  rep(i, N) cin >> A[i];
  int d = 0;
  rep(i, N-1) {
    d = max(d, A[i+1]-A[i]);
  }
  d = max(K+A[0]-A[N-1], d);

  cout << K-d << "\n";
  return 0;
}
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
int K;
int A[100005];
ll B[100005][2]; // MIN, MAX 

int main() {
  INCANT;
  cin >> K;
  rep(i, K) cin >> A[i];
  B[K][0] = 2ll;
  B[K][1] = 2ll;
  for (int i=K-1; i>=0; i--) {
    B[i][0] = (B[i+1][0]+A[i]-1)/A[i]*A[i];
    B[i][1] = B[i+1][1]/A[i]*A[i]+A[i]-1;
    if (B[i][0]>B[i][1]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << B[0][0] << ' ' << B[0][1]  << endl;
  return 0;
}
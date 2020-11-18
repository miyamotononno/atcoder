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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int A[4];

int main() {
  INCANT;
  rep(i, 4) cin >> A[i];
  sort(A, A+4);
  string ans = A[0]+A[3]==A[2]+A[1] || A[3] == A[2]+A[1]+A[0]?"Yes":"No";
  cout << ans << "\n";
  return 0;
}
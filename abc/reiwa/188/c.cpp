#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
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
int n;
typedef pair<int, int> P;
P A[65537], B[65537];

int main() {
  INCANT;
  cin >> n;
  int sz = pow(2,n-1);
  if (n==1) {
    int b,c;
    cin >> b >> c;
    if (c<b) cout << 2 << endl;
    else cout << 1 << endl;
    return 0;
  }
  int a;
  rep(i, sz) {
    cin >> a;
    A[i] = P(a, i+1);
  }
  rep(i,sz) {
    cin >> a;
    B[i] = P(a, i+sz+1);
  }
  sort(A, A+sz);
  sort(B, B+sz);
  if (A[sz-1].first<B[sz-1].first) {
    cout << A[sz-1].second << "\n";
  } else {
    cout << B[sz-1].second << "\n";
  }
  return 0;
}
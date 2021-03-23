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
int A[100005],B[100005],X[100005];

int main() {
  INCANT;
  cin >> n;
  rep(i, n) {
    cin >> A[i] >> B[i] >> X[i];
  }
  bool ng = true;
  int pr = INF;
  rep(i, n) {
    if (X[i]-A[i]>0) {
      pr = min(pr, B[i]);
      ng = false;
    }
  }
  if (ng) {
    cout << -1 << "\n";
    return 0;
  }
  cout << pr << endl;
  return 0;
}
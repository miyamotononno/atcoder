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
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
typedef pair<int, int> P;


// 蟻本の貪欲法で似たようなのがあった!!!!!
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  vector<P> A(N);
  int x,l;
  rep(i, N) {
    cin >> x >> l;
    A[i] = P(x+l, x-l);
  }
  sort(ALL(A));
  int cnt = 0;
  int left = -INF;
  rep(i, N) {
    P p = A[i];
    if (left <= A[i].second) {
      left = A[i].first;
      cnt++;
    }
  }
  cout << cnt << "\n";
  return 0;
}
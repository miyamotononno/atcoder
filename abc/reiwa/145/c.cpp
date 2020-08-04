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
double X[10], Y[10];

double kaizyo(int a, int c) {
  double b = 1ll;
  rep(i, c) {
    b *= a;
    a--;
  }
  return b;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N) cin >> X[i] >> Y[i];
  int a[N] = {};
  rep(i,N) a[i] = i;
  double sum = 0.0; 
  do {
    double distance = 0.0;
    rep(i, N) {
      if (i==0) continue;
      int now = a[i],pre = a[i-1];
      double d = sqrt(pow(X[now]-X[pre], 2)+pow(Y[now]-Y[pre], 2));
      sum+=d;
    }
  } while(next_permutation(a, a + N));
  sum /= kaizyo(N, N);
  cout << fixed << setprecision(8) << sum << endl;
  return 0;
}
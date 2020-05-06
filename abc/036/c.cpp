#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <cmath>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
int b[100001];
typedef pair<int, int> P;
P a[100001];

int main() {
  INCANT;
  cin >> N;
  int c;
  rep(i, N) {
    cin >> c;
    a[i] = P(c,i);
  }
  sort(a, a+N);
  int idx=0;
  int now=a[0].first;
  rep(i, N) {
    P p = a[i];
    if (now != p.first) {
      idx++;
      now = p.first;
    }
    b[p.second]=idx;
  }
  rep(i, N) cout << b[i] << endl;
  return 0;
}
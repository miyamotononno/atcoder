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
int N;
typedef pair<int, int> P;
P q[200005];

int main() {
  INCANT;
  cin >> N;
  int a;
  rep(i, N) {
    cin >> a;
    q[i] = P(a, i);
  }
  sort(q, q+N);
  int MAX=1;
  int cnt=0;
  int prev=-1;
  for (auto p: q) {
    if (p.second > prev) {
      cnt++;
      MAX=max(MAX, cnt);
    } else {
      cnt=1;
    }
    prev=p.second;
  }
  cout << N-MAX << endl;
  return 0;
}
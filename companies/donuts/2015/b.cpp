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
int N, M;
int A[17];
int B[51];
vector<int> I[51];

int main() {
  INCANT;
  cin >> N >> M;
  rep(i, N) cin >> A[i];
  int c;
  rep(i, M) {
    cin >> B[i] >> c;
    int a;
    rep(j, c) {
      cin >> a;
      a--;
      I[i].push_back(a);
    }
  }
  int MAX=0;
  rep(i, 1<<N) {
    bitset<16> b(i);
    if (b.count() != 9) continue;
    int baseP=0;
    rep(j, N) if (b[j]) baseP+=A[j];
    rep(j, M) {
      int cnt=0;
      for (auto u: I[j]) {
        if (b[u]) cnt++;
      }
      if (cnt>=3) baseP+=B[j];
    }
    MAX=max(MAX, baseP);
  }
  
  cout << MAX << "\n";
  return 0;
}
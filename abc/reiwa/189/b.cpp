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
int N;
ll X;
ll V[1003], P[1003]; 

int main() {
  INCANT;
  cin >> N >> X;
  X*=100;
  rep(i, N) {
    cin >> V[i] >> P[i];
  }
  ll d=0ll;
  rep(i, N) {
    d+=V[i]*P[i];
    if (d>X) {
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}
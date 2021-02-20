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
char S[5];

int main() {
  INCANT;
  rep(i, 5) cin >> S[i];

  char c = S[2];
  rep(i, 3) {
    if (S[i] == S[i+1] && S[i+1] == S[i+2]) {
      cout << c << endl;
      return 0;
    }
  }
  cout << "draw" << endl;
  return 0;
}
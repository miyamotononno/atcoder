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
char C[51][101];


int main() {
  INCANT;
  cin >> N;
  rep(i, N) {
    rep(j, 2*N-1) {
      cin >> C[i][j];
    }
  }

  for(int i=N-1; i>=0; i--) {
    for (int j=1; j<=2*N-3; j++) {
      if (C[i][j]=='.' || C[i][j]=='X') continue;
      rep(k, 3) {
        if (C[i+1][j+k-1]=='X') {
          C[i][j]='X';
          break;
        }
      }
    }
  }

  rep(i, N) {
    rep(j, 2*N-1) {
      cout << C[i][j];
    }
    cout << "\n";
  }

  return 0;
}
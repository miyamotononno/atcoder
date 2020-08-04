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
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
int N;
char C[2][55];
vector<bool> A;

int main() {
  INCANT;
  cin >> N;
  rep(i, 2) rep(j, N) cin >> C[i][j];
  
  int idx=0;
  while(idx<N) {
    if (C[0][idx]==C[1][idx]) {
      A.push_back(true);
      idx++;
    }
    else if (idx<N-1 && C[0][idx]==C[0][idx]) {
      A.push_back(false);
      idx+=2;
    }
  }
  ll ret=A[0]?3ll:6ll;
  rep(i, A.size()-1) {
    if (A[i]) ret*=2ll;
    else if (!A[i] && A[i+1]) ret*=1ll;
    else ret*=3ll;
    ret%=MOD;
  }

  cout << ret << "\n";
  return 0;
}
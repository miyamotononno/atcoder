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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
int A[11][11];
// g++ a.cpp -std=gnu++17

int calc(vector<int> group) {
  int sz = group.size();
  if (sz==0 || sz==1) return 0;
  int ret=0;
  rep (i, sz) {
    for (int j = i+1; j<sz; j++)  {
      assert(group[i]!=group[j]);
      ret+=A[group[j]][group[i]];
    }
  }
  return ret;
}

void init() {
  cin >> N;
  int a;
  rep(i, N) {
    for(int j=i+1; j<N; j++) {
      cin >> a;
      A[i][j]=a;
    }
  }
  rep(i, N) {
    rep(j, i) {
      A[i][j] = A[j][i];
    }
  }
}

int main() {
  INCANT;
  init();
  int MAX=-INF;
  rep(bit3, pow(3,N)) {
    vector<int> mod3[3];
    int tmp = bit3;
    for(int i=N-1; i>=0; i--) {
      int mask = pow(3, i);
      mod3[tmp/mask].push_back(i);
      tmp%=mask;
    }
    int ret1 = calc(mod3[0]);
    int ret2 = calc(mod3[1]);
    int ret3 = calc(mod3[2]);
    MAX=max(MAX, ret1+ret2+ret3);
  }
  cout << MAX << "\n";
  return 0;
}
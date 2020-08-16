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
int L[101];

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> L[i];
  sort(L, L+N);
  int cnt=0;
  rep(i, N-2) {
    for (int j=i+1; j<N-1; j++) {
      for (int k=j+1; k<N; k++) {
        if (L[i]==L[j] || L[k]==L[j]) continue;
        if (L[k]<L[i]+L[j]) cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
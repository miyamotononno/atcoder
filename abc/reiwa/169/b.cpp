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
int N;
ll A[100005];

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> A[i];
  rep(i, N) {
    if (A[i]==0) {
      cout << 0 << "\n";
      return 0;
    } 
  }
  ll b18 = 1e18;
  ll a = 1ll;
  int idx=0;
  while(idx<N && b18/a>=A[idx]) {
    a*=A[idx];
    idx++;
  }
  if (idx==N) {
    cout << a << endl;
  } else cout << -1 << "\n";
  return 0;
}
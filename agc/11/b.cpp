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
ll A[100005], SUM[100005];

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> A[i];
  sort(A, A+N);
  SUM[0] = A[0]; 
  rep(i, N) {
    if (i==0) continue;
    SUM[i] = A[i] + SUM[i-1];
  }
  int idx=1;
  rep(i, N) {
    if (i==0) continue;
    if (A[i] > 2*SUM[i-1]) {
      idx=1;
    } else idx++;
  }
  cout << idx << "\n";
  return 0;
}
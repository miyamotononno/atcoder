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
int A[101];

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> A[i];

  ll SUM = pow(3, N);
  ll ODD = 1ll;
  rep(i, N) {
    if (A[i]%2==0) ODD*=2;
    else ODD*=1; 
  }
  cout << SUM-ODD << "\n";
  return 0;
}
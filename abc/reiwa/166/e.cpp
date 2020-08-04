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
int N, A[200005];
unordered_map<int, ll> M;

// i<jのときj-i=A[i]+A[j]
// A[i]+i=j-A[j]
int main() {
  INCANT;
  cin >> N;
  rep(i, N) {
    cin >> A[i];
    M[A[i]+i]++; 
  }
  ll res = 0;
  rep(i, N) res+=M[i-A[i]];

  cout << res << endl;
  return 0;
}
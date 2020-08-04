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
ll T[101];

// -std=gnu++17つけてやらないとエラーになるので注意！！！
int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> T[i];
  ll _gcd = T[0];
  ll lcp=T[0];
  rep(i, N) {
    _gcd = gcd(lcp, T[i]);
    lcp= lcp/_gcd*T[i];
  }
  
  cout << lcp << "\n";
  return 0;
}
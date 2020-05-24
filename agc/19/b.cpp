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
ll n;
string A;
ll M[26];

int main() {
  INCANT;
  cin >> A;
  n = A.size();
  rep(i, n) M[A[i]-'a']++;
  
  ll SUM = n*(n-1)/2+1;
  rep(i, 26) SUM-=M[i]*(M[i]-1)/2;
  cout << SUM << "\n";
  return 0;
}
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
int A,B,C,K;

bool dfs(int a,int b,int c,int k) {
  if (a < b && b < c) return true;
  if (k>0) {
    if (dfs(a*2, b, c, k-1)) return true;
    if (dfs(a, b*2, c, k-1)) return true;
    if (dfs(a, b, c*2, k-1)) return true;
  }
  return false;
}

int main() {
  INCANT;
  cin >> A >> B >> C >> K;

  string ans = dfs(A,B,C,K)?"Yes":"No";
  cout << ans << "\n";
  return 0;
}
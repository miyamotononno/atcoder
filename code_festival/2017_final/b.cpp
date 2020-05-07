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
string S;

bool dfs(int idx, int pre, int prepre, vector<int> C) {
  if (idx==N) return true;
  rep(i,3) {
    if (i==pre || i==prepre) continue;
    if (C[i]==0) continue;
    C[i]--;
    bool flag = dfs(idx+1, i, pre, C);
    if (flag) return true;
    C[i]++;
  }
  return false;
}

int main() {
  INCANT;
  cin >> S;
  N = S.size();
  vector<int> C(3);
  for (auto p: S) C[p-'a']++;
  string ans = dfs(0,'-', '-', C)? "YES":"NO";
  cout << ans << endl;
  return 0;
}
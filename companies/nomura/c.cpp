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
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
ll A[100003], SUM[100003];

ll dfs(int idx, ll cc) {
  if (idx==N+2) return 0ll;
  ll max_node = min(SUM[idx], cc);
  ll nc = max_node-A[idx];
  if (nc < 0) return - INF; 
  return dfs(idx+1, nc*2)+max_node;
}

int main() {
  INCANT;
  cin >> N;
  rep(i, N+1) cin >> A[i];
  SUM[N] = A[N];
  for(int i=N-1; i>=0; i--) SUM[i] += A[i]+SUM[i+1];
  
  ll ret = dfs(0, 1);
  if (ret<0) cout << -1 << endl;
  else cout << ret << endl;
}
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N, Q;
vector<int> T[200002];
ll X[200002];
ll Ans[200002];

void dfs(int num, ll value){
  rep(i, T[num].size()){
    int next = T[num][i];
    dfs(next, value+X[num]);
  }
  Ans[num] = value+X[num];
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> Q;
  int a, b;
  rep(i, N-1){
    cin >> a >> b;
    a--; b--;
    T[a].push_back(b);
  }
  int p;
  ll x;
  rep(i, Q){
    cin >> p >> x;
    p--;
    X[p] += x;
  }
  dfs(0, 0);
  rep(i, N) cout << Ans[i] << ' ';
  return 0;
}
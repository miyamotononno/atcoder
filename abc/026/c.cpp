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
const int INF = 1000000007;
int N;
vector<int> L[21];

int dfs(int num){
  int mx = 0;
  int mn = INF;
  if (L[num].size() == 0) return 1;
  for (int i=0; i< L[num].size(); i++){
    int r = dfs(L[num][i]);
    mn = min(mn, r);
    mx = max(mx, r);
  }
  return mn + mx + 1;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int a;
  rep(i, N-1){
    cin >> a;
    a--;
    L[a].push_back(i+1);
  }

  int ans = dfs(0);
  cout << ans << endl;
  return 0;
}
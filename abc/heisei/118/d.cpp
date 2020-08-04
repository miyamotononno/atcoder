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
int N, M;
vector<int> B[10005];
int cost[9] = {2,5,5,4,5,6,3,7,6};
typedef pair<vector<int>, bool> P;

// 0.制作可能 1.桁数が大きい 2.番号が大きいの順にreturnする
P dfs(int rest, vector<int> &A) { // 残りcost
  vector<int> ret;
  if (rest==0) return P(ret, true);
  if (rest<0) return P(ret, false);
  if (B[rest].size()>0) return P(B[rest], true);
  int c = 0;
  rep(i, M) {
    P p = dfs(rest-cost[A[i]], A);
    if (p.second && p.first.size()>=ret.size()) {
      ret = p.first;
      c=A[i]+1;
    }
  }
  if (c == 0) return P(ret, false);
  ret.push_back(c);
  B[rest] = ret;
  return P(ret, true);
}

int main() {
  INCANT;
  cin >> N >> M;
  vector<int> A(M);
  int a; 
  rep(i, M) {
    cin >> a;
    a--;
    A[i] = a;
  }
  sort(ALL(A));
  P p = dfs(N, A);
  int sz =B[N].size();
  rep(i, sz) cout << B[N][sz-1-i];
  cout << endl;
  
  return 0;
}
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
int A,B,C;
double dp[100][100][100];

double calc(int a, int b, int c, int i) {
  double bunbo = (double) a+b+c;
  if (i==0) return double(a) / bunbo;
  if (i==1) return double(b) / bunbo;
  if (i==2) return double(c) / bunbo;
  return -1;
}

double dfs(int a, int b, int c) {
  if (a==100 || b==100 || c==100) return 0.0;
  if (dp[a][b][c]>0) return dp[a][b][c];
  double ret= 0.0;
  if (a!=0) ret+=calc(a,b,c,0)*(dfs(a+1, b,c)+1);
  if (b!=0) ret+=calc(a,b,c,1)*(dfs(a, b+1,c)+1);
  if (c!=0) ret+=calc(a,b,c,2)*(dfs(a, b,c+1)+1);
  dp[a][b][c]=ret;
  return ret;
}

int main() {
  INCANT;
  cin >> A >> B >> C;
  
  cout << dfs(A,B,C) << endl;
  return 0;
}
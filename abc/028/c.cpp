#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <cmath>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
string S;
int M[5];
priority_queue<int> que;

void dfs(int idx, int rest, int SUM) {
  if (rest==0) {
    que.push(SUM);
    return;
  }
  if (idx==5) return;
  dfs(idx+1, rest, SUM);
  dfs(idx+1, rest-1, SUM+M[idx]);
}


int main() {
  INCANT;
  rep(i, 5) cin >> M[i];
  dfs(0,3,0);
  que.pop();
  que.pop();
  cout << que.top() << endl;
  return 0;
}
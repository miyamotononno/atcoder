#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
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
int n, m;
int A[1500003];
int counts[1500003];
priority_queue<int, vector<int>, greater<int> > que;

int main() {
  INCANT;
  cin >> n >> m;
  rep(i, n) cin >> A[i];
  rep(i, m) {
    counts[A[i]]++; 
  }
  rep(i, n+1) {
    if (counts[i]==0) que.push(i);
  }
  int ans = que.top();
  rep(lft, n-m) {
    int rgt = lft+m;
    counts[A[lft]] = max(0, counts[A[lft]]-1);
    counts[A[rgt]]++;
    if (counts[A[lft]]==0) {
      que.push(A[lft]);
    }
    int q;
    while(!que.empty()) {
      q = que.top();
      if (counts[q]>0) {
        que.pop();
        continue;
      } else break;
    }
    ans = min(ans, q);
  }
  cout << ans << endl;
  return 0;
}
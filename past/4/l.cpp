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
int n, q;
ll h[200005];
ll X;
unordered_map<ll, int> U; 

int main() {
  INCANT;
  cin >> n >> q;
  rep(i, n) cin >> h[i];
  for (int i=0; i<n; i+=2) {
    if (i>0) U[h[i]-h[i-1]]++;
    if (i<n-1) U[h[i]-h[i+1]]++;
  }
  int t;ll v;
  int cnt;
  vector<int> ans(q);
  rep(i, q) {
    cin >> t;
    if (t==3) {
      int u;
      cin >> u >> v;
      u--;
      if (u%2==0) {
        if (u>0) {
          U[h[u]-h[u-1]]--;
          U[h[u]+v-h[u-1]]++;
        }
        if (u<n-1) {
          U[h[u]-h[u+1]]--;
          U[h[u]+v-h[u+1]]++;
        }
      } else {
        if (u>0) {
          U[h[u-1]-h[u]]--;
          U[h[u-1]-h[u]-v]++;
        }
        if (u<n-1) {
          U[h[u+1]-h[u]]--;
          U[h[u+1]-h[u]-v]++;
        }
      }
      h[u]+=v;
    } else {
      cin >> v;
      if (t%2) X-=v;
      else X+=v;
    }
    ans[i]=U[X];
  }
  for (auto p: ans) cout << p << endl; 
  return 0;
}
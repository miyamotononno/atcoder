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
int n;
int A[200005];
int B[200005];

vector<int> prime_factor(int s) {
  vector<int> ret;
  if (s==1) return ret;
  for (int i=1; i*i<=s; i++) {
    if (s%i==0) {
      if (i*i==s) ret.push_back(i);
      else {
        ret.push_back(i);
        if (i!=1) ret.push_back(s/i); // 自身は入れないことに注意
      }
    }
  }
  return ret;
}

int main() {
  INCANT;
  cin >> n;
  rep(i, n) cin >> A[i+1];
  vector<int> ans;
  for (int i=n; i>=1; i--) {
    B[i] += A[i];
    B[i]%=2;
    if (B[i]) ans.push_back(i);
    if (B[i]) {
      vector<int> pf = prime_factor(i);
      for (auto p: pf) B[p]++;
    }
  }
  int m=ans.size();
  cout << m << endl;
  if (m>0) {
    for (int i=m-1; i>=0; i--) {
      cout << ans[i] << ' ';
    }
    cout << endl;
  }
  
  return 0;
}
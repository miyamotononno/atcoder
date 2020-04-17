#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <stack>
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

int main() {
  INCANT;
  cin >> N;
  vector<int> v(N);
  rep(i, N) cin >> v[i];
  vector<int> ans;
  while(v.size()>0) {
    stack<int> tmp;
    rep(i, v.size()) {
      if (v[i]==i+1) tmp.push(i);
    }
    if (tmp.empty()) {
      cout <<  -1 << endl;
      return 0;
    }
    
    ans.push_back(v[tmp.top()]);
    v.erase(v.begin()+tmp.top());
    tmp.pop();
  }

  for (int i=N-1; i>=0; i--) cout << ans[i] << endl;
  return 0;
}
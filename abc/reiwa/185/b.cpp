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
int n,m,t;
int a[1001], b[1001];

int main() {
  INCANT;
  cin >> n >> m >> t;
  vector<int> vec;
  rep(i, m) {
    cin >> a[i] >> b[i];    
  }
  vec.push_back(-a[0]);
  rep(i, m) {
    vec.push_back(b[i]-a[i]);
    if (i<m-1) vec.push_back(b[i]-a[i+1]);
    else vec.push_back(b[i]-t);
  }
  int ret = n;
  rep(i, vec.size()) {
    ret+=vec[i];
    if (ret>=n) ret=n;
    if (ret<=0) {
      cout << "No" << "\n";
      return 0;
    }
  }
  
  cout << "Yes" << "\n";
  
  return 0;
}
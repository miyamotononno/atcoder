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
int a[200005];

int main() {
  INCANT;
  cin >> n >> m;
  rep(i, m) {
    cin >> a[i];
    a[i]--;
  }
  if (m==0) {
    cout << 1 << endl;
    return 0;  
  }
  if (n==m) {
    cout << 0 << endl;
    return 0;
  }
  sort(a, a+m);
  vector<int> vec;
  if (a[0]>0) vec.push_back(a[0]);
  rep(i, m-1) {
    if (a[i+1]-a[i]-1>0) vec.push_back(a[i+1]-a[i]-1);
  }
  if (a[m-1]<n-1) vec.push_back(n-1-a[m-1]);
  sort(ALL(vec));
  int d = vec[0];
  int ret =0; 
  for (auto c: vec) {
    ret+=(c+d-1)/d;
  }
  cout << ret << "\n";
  return 0;
}
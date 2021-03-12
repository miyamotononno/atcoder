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
int n, k;
unordered_map<int, int> U;

int f(int num) {
  vector<int> s,t;
  while(num!=0) {
    int d = num%10;
    s.push_back('0'+d);
    t.push_back('0'+d);
    num/=10;
  }
  sort(ALL(s));
  sort(ALL(t), greater<char>());
  int ret = 0;
  rep(i, s.size()) {
    int d = t[i]-s[i];
    ret*=10;
    ret+=d;
  }
  return ret;
}

int main() {
  INCANT;
  cin >> n >> k;
  if (n==0) {
    cout << 0 << endl;
    return 0;
  }
  int d = n;
  rep(i, k) {
    d = f(d);
    if (d==0) {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << d << endl;
  return 0;
}
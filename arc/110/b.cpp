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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n;
string t;

bool check(const string &s) {
  bool ok=true;
  int i=0;
  if (s[0]=='0') {
    for (i=1; i<=n-3; i+=3) {
      ok = s[i]=='1' && s[i+1]=='1' && s[i+2]=='0';
      if (!ok) return false;
    }
    // 最後まで行った場合はおk
  }
  if (s[0]=='1') {
    if (s[1]=='1') {
      for (i=0; i<=n-3; i+=3) {
        bool ok = s[i]=='1' && s[i+1]=='1' && s[i+2]=='0';
        if (!ok) return false;
      }
    } else { // s[1]=='0'
      for (i=2; i<=n-3; i+=3) {
        bool ok = s[i]=='1' && s[i+1]=='1' && s[i+2]=='0';
        if (!ok) return false;
      }
    }
  }

  if (i==n-2) {
    ok = s[i]=='1' && s[i+1]=='1';
    if (!ok) return false;
  } else if (i==n-1) {
    ok = s[i]=='1';
    if (!ok) return false;
  }
  return true;
}

int main() {
  INCANT;
  cin >> n;
  cin >> t;
  if (n==1) {
    ll ans;
    if (t[0]=='0') {
      ans =1e10;
      cout << ans << endl;
    } else {
      ans =2e10;
      cout << ans << endl;
    }
    return 0;
  }
  if (n==2) {
    ll ans;
    if (t=="10" || t=="11") {
      ans =1e10;
      cout << ans << endl;
    } else if (t=="01") {
      ans = 1e10-1;
      cout << ans << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }

  if (!check(t)) {
    cout << 0 << endl;
    return 0;
  }

  ll pre;
  if (t[0]=='1' && t[1]=='0') pre=1;
  else if (t[0]=='0') pre=2;
  else if (t[0]=='1' && t[1]=='1' && t[2]=='0') pre=0;
  else {
    cout << 0 << endl;
    return 0;
  }
  ll lt;
  if (t[n-1]=='1' && t[n-2]=='1') lt=1;
  else if (t[n-1]=='1' && t[n-2]=='0') lt =2;
  else if (t[n-3]=='1' && t[n-2]=='1' && t[n-1]=='0') lt=0;
  else {
    cout << 0 << endl;
    return 0;
  }
  ll original = 3e10-pre-lt;
  ll ans = (original-n)/3+1;
  cout << ans << endl;
  return 0;
}
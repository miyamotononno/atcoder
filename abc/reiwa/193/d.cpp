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
int k;
unordered_map<int, int> s,t, rest;

int winTaka(int taka, int aoki, unordered_map<int, int> s, unordered_map<int, int> t) {
  s[taka]++;
  t[aoki]++;
  int total = 0;
  for (int i=1; i<10; i++) {
    int e = int(pow(10, s[i]))-int(pow(10, t[i]));
    total+= i*e;
  }
  return total>0.0;
}

int main() {
  INCANT;
  cin >> k;
  char c;
  rep(i, 5) {
    cin >> c;
    if (i==4) continue;
    s[c-'0']++;
  }
  rep(i, 5) {
    cin >> c;
    if (i==4) continue;
    t[c-'0']++;
  }
  
  rep(i, 9) {
    int num = i+1;
    rest[num] = k-s[num]-t[num];
  }
  double denominator = 9*k-8;
  double coeffient;
  double ans = 0.0;
  for(int i=1; i<10; i++) {
    for (int j=1; j<10; j++) {
      if (i==j && rest[i]-2<0) continue;
      if (rest[i]-1<0) continue;
      if (rest[j]-1<0) continue;
      if (i==j) {
        coeffient = double(rest[i]) * double(rest[i]-1);
      } else {
        coeffient = double(rest[i]) * double(rest[j]);
      }
      coeffient/=denominator;
      coeffient/=(denominator-1);
      
      ans+=coeffient * winTaka(i, j, s,t);
    }
  }
  cout << ans << "\n";
  return 0;
}
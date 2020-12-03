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
int n,m;
int d[3];

int calc() {
  if (n==0) return d[0];
  int ret=0;
  if (n==1) {
    rep(i, 2) {
      ret+=d[i]*pow(10, i);
    }
    return ret;
  }
  if (n==2) {
    rep(i, 3) {
      ret+=d[i]*pow(10, i);
    }
    return ret;
  }
}

int main() {
  INCANT;
  cin >> n >> m;
  n--;
  int s,c;
  rep(i,3) d[i]=-1;
  bool ng = false;
  rep(i, m) {
    cin >> s >> c;
    s--;
    if (s>n || (d[n-s]>=0 && d[n-s]!=c)) ng = true;
    d[n-s] = c;
  }
  if (ng || (n>0 && d[n]==0)) {
    cout << -1 << "\n";
    return 0;
  }
  if (d[0]==-1) d[0]=0; // n桁目
  if (d[1]==-1) { // n-1桁目
    if (n==1) {
      d[1] = 1;
    } else {
      d[1] = 0;
    }
  }
  if (n==2 && d[2]==-1) { // 3桁目
    d[2] = 1;
  }
  cout << calc() << endl;
  return 0;
}
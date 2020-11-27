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
const ll MOD = 1e9;
int k, q;
ll X[100005]; // i番目の操作で、それ単体で増える転倒数
ll Cnts[100005][21]; // i番目の操作で含まれる数字の数
ll Total[21];

int main() {
  INCANT;
  cin >> k;
  rep(i, k) {
    int n;
    cin >> n;
    ll cnt=0ll;
    rep(j, n) {
      int a;
      cin >> a;
      Cnts[i][a]++;
      for (int l=a+1; l<=20; l++) cnt+= Cnts[i][l];
    }
    X[i]=cnt;
  }

  cin >> q;
  ll ret = 0ll;
  rep(i, q) {
    int b;
    cin >> b;
    b--;
    ret+=X[b];
    ret%=MOD;
    for (int j=1; j<=19; j++) {
      for (int l=j+1; l<=20; l++) {
        ret+=Cnts[b][j]*Total[l];
        ret%=MOD;
      }
    }
    for (int j=1; j<=20; j++) {
      Total[j]+=Cnts[b][j];
    }
  }
  cout << ret << endl;
  return 0;
}
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
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
ll w;
ll A[200005];
ll SUM[200005];

int main() {
  INCANT;
  cin >> n >> w;
  int s,t;
  ll p;
  rep(i, n) {
    cin >> s >> t >> p;
    A[s]+=p;
    A[t]-=p;
  }
  rep(i, 200003) {
    if (i==0) {
      SUM[i] = A[0];
      if (A[0]>w) {
        cout << "No" << endl;
        return 0;
      }
    }
    else {
      SUM[i] += SUM[i-1]+A[i];
      if (SUM[i]>w) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
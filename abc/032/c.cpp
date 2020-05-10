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
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
ll K, s[100005];

int main() {
  INCANT;
  cin >> N >> K;
  bool flag = false;
  rep(i, N) {
    cin >> s[i];
    if (s[i]==0) flag=true;
  }
  if (flag) {
    cout << N << endl;
    return 0;
  }
  
  int l_idx=0;
  int MAX=0;
  ll SUM=1ll;
  rep(r_idx, N) {
    SUM*=s[r_idx];
    while(SUM>K && l_idx<=r_idx) {
      SUM/=s[l_idx];
      l_idx++;
    }
    MAX=max(MAX, r_idx-l_idx+1);
  }
  cout << MAX << endl;
}
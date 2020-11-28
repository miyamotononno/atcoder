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
int a,b,x,y;

int main() {
  INCANT;
  cin >> a >> b >> x >> y;
  if (a==b) {
    cout << x << endl;
    return 0;
  }
  int ret=INF;
  ret = min(ret, abs(b-a)*y+x);
  if (a<b) {
    ret = min(ret, (abs(b-a)*2+1)*x);
  } else {
    ret = min(ret, (abs(b-a)*2-1)*x);
  }
  
  ret = min(ret,abs(b-(a-1))*y+x); // Aa-> A_b+1 -> Bb
  cout << ret << endl;
  return 0;
}
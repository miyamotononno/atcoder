#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
ll L, R;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> L >> R;
  if (R-L >=2019){
    cout << 0 << endl;
    return 0;
  }
  L%=2019;
  R%=2019;
  if (L > R){
    cout << 0 << endl;
    return 0;
  }

  int ans = 2018;
  for(int i=L; i<R; i++){
    for(int j=i+1; j<=R; j++){
      ans = min(ans, (i*j)%2019);
      if (ans ==0) break;
    }
    if (ans ==0) break;
  }

  cout << ans << endl;
  return 0;
}
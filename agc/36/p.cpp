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
const ll MOD = 1000000007LL;
ll S;

bool IsPrime(ll num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2){
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;

  bool flag = IsPrime(S);
  if (flag){
    cout << 0 << ' ' << 0 << ' ' << 1 <<' ' << 2 << ' '<< (S+1)/2 << ' ' << 1 << endl;
  }else{
    cout << 0 << ' ' << 0 << ' ' << 1 <<' ' << 0 << ' '<< S << ' ' << 1 << endl;
  }
  return 0;
}
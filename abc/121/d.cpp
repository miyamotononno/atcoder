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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
ll A, B;

// if n%2==0で、n xor (n+1) = 1;

// 0始まりなことに注意
ll calc(ll num){
  if (num%4==3){
    return 0ll;
  }
  else if (num%4==0){
    return num;
  }
  else if (num%4==1){
    return 1ll;
  }
  else{
    return num+1ll;
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B;

  ll a = calc(A-1);
  ll b = calc(B);

  cout << (a^b) << endl;

  return 0;
}
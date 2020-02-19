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
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
string S;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  int N = S.size();
  ll ret = 0ll;
  bool plus1 = false;
  for (int i=N-1; i>=0; i--) {
    ll n = S[i] - '0';
    n = plus1?n+1:n;
    if (n>5) {
      plus1 = true;
      ret+=10-n;
    } else if (n==5){
      if (i>0& S[i-1]-'0' >= 5) {
        plus1 = true;
        ret+=5ll;
      } else {
        plus1 = false;
        ret+=5ll;
      }
    } else {
        plus1 = false;
        ret+=n;
    }
  }
  cout << ret + plus1<< "\n";
  return 0;
}
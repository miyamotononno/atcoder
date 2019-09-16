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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
string S;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  rep(i, S.size()) {
    if (i%2==0 && S[i]=='L'){
      cout << "No" << "\n";
      return 0;
    }
    if (i%2==1 && S[i]=='R'){
      cout << "No" << "\n";
      return 0;
    }
  }

  cout << "Yes" << "\n";
  return 0;
}
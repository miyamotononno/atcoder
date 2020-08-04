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
const int INF = 1000000007;
string S;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  int ans = INF;
  rep(i, S.size()-2){
    int a = (S[i] - '0')*100+(S[i+1] - '0')*10+S[i+2] - '0';
    ans = min(ans, abs(753-a));
  }

  cout << ans << "\n";
  return 0;
}
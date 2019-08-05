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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
string S;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;

  int f_a = 0;
  int f_b = 0;
  int f_c = 0;

  rep(i, S.size()){
    if (S[i] == 'a')f_a++;
    if (S[i] == 'b')f_b++;
    if (S[i] == 'c')f_c++;
  }
  bool flag = false;
  if (f_a == 1 && f_b == 1 && f_c == 1) flag = true;
  string ans = flag?"Yes":"No";
  cout << ans << endl;
  return 0;
}
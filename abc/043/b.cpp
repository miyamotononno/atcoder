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
#include <unordered_map>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
string s;
stack<char> St;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  int n = s.size();
  rep(i, n) {
    if (s[i]=='B') {
      // popは空だとエラーになるので気をつける事
      if (!St.empty()) St.pop();
    } else St.push(s[i]);
  }
  string t = "";
  while (!St.empty()) {
    char c = St.top(); 
    t += c;
    St.pop();
  }
  reverse(ALL(t));
  cout << t << "\n";
  return 0;
}
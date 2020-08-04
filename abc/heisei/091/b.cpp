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
using namespace std;
int N, M;
string s[101], t[101];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  map<string, int> m;

  cin >> N;
  rep(i, N) cin >> s[i];
  cin >> M;
  rep(i, M) cin >> t[i];
    
  rep(i, N) m[s[i]]++;
  rep(i, M) m[t[i]]--;
  
  int ans=0;
  rep(i, N) ans= max(ans, m[s[i]]);

  cout << ans << endl;

  return 0;
}
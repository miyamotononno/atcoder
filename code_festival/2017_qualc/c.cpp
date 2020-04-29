#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
string s;
vector<int> B;

int main() {
  INCANT;
  cin >> s;
  int N = s.size();
  rep(i, N) if (s[i]!='x') B.push_back(i);
  int b =B.size();
  rep(i, b/2) {
    if (s[B[i]] != s[B[b-1-i]]) {
      cout << -1 << "\n";
      return 0;
    } 
  }

  int left = 0;
  int right = N-1;
  int ans = 0;
  rep(i, b/2) {
    int tmp = abs((B[i]-left) - (right-B[b-1-i]));
    ans+=tmp;
    left = B[i];
    right = B[b-1-i];
  }
  if (b%2==1) ans+=abs((B[b/2]-left)- (right-B[b/2]));
  cout << ans << "\n";
  return 0;
}
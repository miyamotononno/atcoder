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
bool S[501][26];

int main() {
  INCANT;
  cin >> N;
  char c;
  rep(i, N) {
    rep(j, N) {
      cin >> c;
      S[i][c-'a']=true;
    }
  }

  vector<char> Ans(N); 
  rep(i, (N+1)/2) {
    int rIdx = N-1-i;
    bool flag = true;
    rep(j, 26) {
      if (S[i][j]&&S[rIdx][j]) {
        Ans[i] = char('a'+j);
        Ans[rIdx] = char('a'+j);
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << -1 << endl;
      return 0;
    }
  }
  rep(i, N) cout << Ans[i];
  cout << endl;
  return 0;
}
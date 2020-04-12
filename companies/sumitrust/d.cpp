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
string S;
typedef pair<bool, int> P;
set<string> St;
bool DP[30005][11][11];

void dfs(int idx, char a, char b, char c) {
  if (idx==N) return;
  int _a = a=='n'?10:a-'0';
  int _b = b=='n'?10:b-'0';
  if (DP[idx][_a][_b]) return;
  rep(i, 2) {
    if (i==0) {
      dfs(idx+1, a,b,c);
      DP[idx][_a][_b] = true;
    } else {
      if (a=='n') {
        a = S[idx];
        dfs(idx+1, a, 'n', 'n');
        DP[idx][_a][10] =true;
      } else if (b=='n') {
        b = S[idx];
        dfs(idx+1, a, b, 'n');
        DP[idx][_a][_b]=true;
      } else if (c=='n') {
        c = S[idx];
        string d = "";
        d+=a;d+=b;d+=c;
        St.insert(d);
      }
    }
  }
  return;
}

int main() {
  INCANT;
  cin >> N >> S;
  dfs(0, 'n', 'n', 'n');
  cout << St.size() << "\n";
  return 0;
}
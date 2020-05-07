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
int n;
string S;
string KIHBR = "KIHBR"; 
int c[4] = {0,3,4,5};
vector<string> V;

int main() {
  INCANT;
  cin >> S;
  n = S.size();
  rep(i, 1<<4) {
    queue<int> que;
    rep(j, 4) {
      int mask = 1 << j;
      if (i & mask) que.push(c[j]);
    }
    string T = "";
    rep(j, 6) {
      if (!que.empty() && j==que.front()) {
        T.push_back('A');
        que.pop();
      }
      if (j<5) T.push_back(KIHBR[j]);
    }
    if (S==T) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
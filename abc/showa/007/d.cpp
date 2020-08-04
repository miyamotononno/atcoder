#include <algorithm>
#include <iostream>
#include <sstream>
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
ll A, B;
ll DP[30][2][2]; // 決定した桁数, N以下が確定, 4,9が含まれているか

ll calc(string &S) {
  const int length = S.size();
  rep(i, 30) rep(j, 2) rep(k,2) DP[i][j][k] = 0ll;
  DP[0][0][0] = 1ll; // 0は0桁の唯一の4,9を含まない整数
  rep(i,length) {
    const int e = S[i] - '0';
    rep(j,2) {
      rep(k,2) {
        const int itr = j?9:e;
        rep(l,itr+1) {
          DP[i+1][j || (l<e)][k || l==4 || l==9] += DP[i][j][k];
        } 
      }
    }
  }
  
  return DP[length][1][1]+DP[length][0][1];
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B;
  A--;
  string As = to_string(A);
  string Bs = to_string(B);
  ll a = calc(As);
  ll b = calc(Bs);
  cout << b - a << "\n";
  return 0;
}
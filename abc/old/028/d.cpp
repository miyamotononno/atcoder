#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <cmath>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
string S;
ll N,K;

// 中央値Kの余事象は,
// 全てKより大きい
// 2つKより大きく一つはK未満
// 小さいのも同様

int main() {
  INCANT;
  cin >> N >> K;
  ll TOTAL = pow(N,3);
  ll p = pow(N-K, 3);
  p += 3*pow(N-K,2)*K;
  p += pow(K-1,3);
  p += 3*pow(K-1,2)*(N-K+1);
  double re = double(TOTAL-p)/double(TOTAL);
  cout << re << endl;
  return 0;
}
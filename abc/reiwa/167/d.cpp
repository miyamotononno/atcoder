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
int N,A[200004];
ll K;
int doubling[61][200004]; // ダブリング. 街jから2^i進めた街

int main() {
  INCANT;
  cin >> N >> K;
  rep(i, N) {
    cin >> A[i];
    A[i]--;
  }
  rep(i, N) doubling[0][i]=A[i];
  // 自分の街jの2^(i+1)後の街は、自分の街から2^i後の街からさらに2^i進んだ街に等しい
  rep(i, 60) {
    rep(j, N) doubling[i+1][j] = doubling[i][doubling[i][j]];
  }
  int n=0;
  rep(i, 60) {
    if ((K>>i) & 1) n = doubling[i][n]; 
  }
  cout << n+1 << endl;
  return 0;
}
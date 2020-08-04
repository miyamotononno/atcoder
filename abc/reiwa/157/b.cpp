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
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
int A[3][3];
int b[11];
int ok[3][3];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  rep(i, 3) {
    rep(j,3) cin >> A[i][j];
  }
  cin >> N;
  rep(i, N) cin >> b[i];
  rep(i, N) {
    rep(j,3) {
      rep(k,3) {
        if (A[j][k]==b[i]) ok[j][k]=1;
      }
    }
  }
  rep(i,3){
    int sm = 0;
    rep(j, 3) sm+=ok[i][j];
    if (sm==3) {
      cout << "Yes" << "\n";
      return 0;
    }
  }

  rep(i,3){
    int sm = 0;
    rep(j, 3) sm+=ok[j][i];
    if (sm==3) {
      cout << "Yes" << "\n";
      return 0;
    }
  }

  if (ok[0][0]+ok[1][1]+ok[2][2]==3){
      cout << "Yes" << "\n";
      return 0;
  }

  if (ok[0][2]+ok[1][1]+ok[2][0]==3){
      cout << "Yes" << "\n";
      return 0;
  }

  cout << "No" << "\n";
  return 0;
}
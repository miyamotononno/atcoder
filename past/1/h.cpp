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
typedef long long ll;
using namespace std;
const int INF = 2e9;
int N, Q, C[200006];
int S[200006][3];
// g++ a.cpp -std=gnu++17

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> C[i];
  cin >> Q;
  rep(i, Q) {
    cin >> S[i][0];
    if (S[i][0]==1) {
      cin >> S[i][1] >> S[i][2];
      S[i][1]--;
    } else cin >> S[i][2];
  }
  
  int MIN_ODD = INF;
  int MIN_EVEN = INF;
  rep(i, N) {
    if (i%2==0) MIN_ODD = min(C[i], MIN_ODD);
    else MIN_EVEN=min(C[i], MIN_EVEN);
  }
  int substractOdd=0;
  int substractEven=0;
  ll ANS=0ll;
  rep(i, Q) {
    int qry = S[i][0];
    if (qry==1) {
      int idx = S[i][1];
      if (idx%2==1 && C[idx]<substractEven+S[i][2]) continue;
      if (idx%2==0 && C[idx]<substractOdd+S[i][2]) continue;
      C[idx]-=S[i][2];
      ANS+=(ll)S[i][2];
      if (idx%2==0) MIN_ODD=min(C[idx], MIN_ODD);
      else MIN_EVEN=min(C[idx], MIN_EVEN);
    } else if (qry==2) {
      if (S[i][2]+substractOdd>MIN_ODD) continue;
      substractOdd += S[i][2];
      ANS+=(1ll)*S[i][2]*((N+1)/2);
    } else {
      if (S[i][2]+substractEven>MIN_EVEN) continue;
      if (S[i][2]+substractOdd>MIN_ODD) continue;
      substractEven += S[i][2];
      substractOdd += S[i][2];
      ANS+=(1ll)*S[i][2]*N;
    }
  }
  cout << ANS << "\n";
  return 0;
}
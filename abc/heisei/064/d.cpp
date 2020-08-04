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
int N, SUML[101], SUMR[101];
string S;

// Sの左側には(, 右側には)しかこない

int main() {
  INCANT;
  cin >> N >> S;

  if (S[0]=='(') SUML[0]=1;
  else SUMR[0]=1;
  rep(i, N) {
    if (!i) continue;
    char c = S[i];
    if (c=='(') {
      SUML[i] +=SUML[i-1]+1;
      SUMR[i] = SUMR[i-1];
    } else {
      SUMR[i] += SUMR[i-1]+1;
      SUML[i] = SUML[i-1];     
    }
  }
  int left=0;
  rep(i, N) left=max(left, SUMR[i]-SUML[i]);
  rep(i, N) SUML[i]+=left;
  int right = SUML[N-1] - SUMR[N-1];
  rep(i,left) cout << '(';
  cout << S;
  rep(i, right) cout << ')';
  cout << endl; 
  return 0;
}
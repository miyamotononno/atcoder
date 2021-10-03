#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
string S, T;

int main() {
  INCANT;
  cin >> S >> T;
  int noSame = 0;
  for (int i=0; i<S.size(); i++) {
    if (S[i]!=T[i]) noSame++;
  }
  if (noSame==0) {
    cout << "Yes" << "\n";
    return 0;
  } else if (noSame == 1 || noSame >= 3) {
    cout << "No" << "\n";
    return 0;
  }
  for (int i=0; i<S.size()-1; i++) {
    if (S[i]!=T[i]) {
      swap(S[i], S[i+1]);
    }
  }
  for (int i=0; i<S.size(); i++) {
    if (S[i]!=T[i]) {
      cout << "No" << "\n";
      return 0;
    }
  }
  cout << "Yes" << "\n";
  return 0;
}
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
string S;

int main() {
  INCANT;
  cin >> S;
  int n = S.size();
  rep(i, n) {
    char d = toupper(S[i]);
    if (i%2==0) {
      if (S[i]==d) {
        cout << "No" << endl;
        return 0;
      }
    } else {
      if (S[i]!=d) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << "\n";
  return 0;
}
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
int M[6];

int main() {
  INCANT;
  cin >> S;
  rep(i, S.size()) M[S[i]-'A']++;
  rep(i, 6) {
    cout << M[i];
    if (i<5) cout << ' ';
    else cout << "\n"; 
  }
  return 0;
}
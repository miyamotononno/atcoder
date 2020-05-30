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
int N, F[3];
string S;

int main() {
  INCANT;
  cin >> S;
  N=S.size();
  rep(i, N) {
    F[S[i]-'a']++;
  }
  int MAX=0;
  int idx=-1;
  rep(i, 3) {
    if (MAX<F[i]) {
      idx=i;
      MAX=F[i]; 
    }
  }
  cout << char('a'+idx) << "\n";
  return 0;
}
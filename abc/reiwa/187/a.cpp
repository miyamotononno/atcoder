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
string A,B;

int main() {
  INCANT;
  cin >> A >> B;
  int a=0;
  int b=0;
  rep(i, 3) {
    a+=A[i]-'0';
  }
  rep(i, 3) {
    b+=B[i]-'0';
  }
  cout << max(a,b) << "\n";
  return 0;
}
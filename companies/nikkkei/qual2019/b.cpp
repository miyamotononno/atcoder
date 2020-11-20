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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n;
string A,B,C;

int main() {
  INCANT;
  cin >> n;
  cin >> A >> B >> C;
  int ret = 0;
  rep(i, n) {
    char a = A[i];
    char b = B[i];
    char c = C[i];
    if (a==b && b==c) continue;
    if (a == b && b!=c) {
      ret+=1;
      continue;
    }
    if (a != b && b==c) {
      ret+=1;
      continue;
    }
    if (a != b && a==c) {
      ret+=1;
      continue;
    }
    ret+=2;
  }
  cout << ret << endl;
  return 0;
}
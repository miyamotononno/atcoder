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
int N, a[105];
int c[9];
int MAX,MIN;

int main() {
  INCANT;
  cin >> N;
  int a;
  rep(i, N) {
    cin >> a;
    a/=400;
    if (a>=9) a=8;
    c[a]++;
  }
  int r=0;
  rep(i, 8) if (c[i]) r++;
  MAX=r+c[8];
  MIN=r+((c[8]>0 && r==0)?1:0);
  cout << MIN << ' ' << MAX << "\n";
  return 0;
}
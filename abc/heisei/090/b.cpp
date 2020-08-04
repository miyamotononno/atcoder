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
int A, B;

int main() {
  INCANT;
  cin >> A >> B;
  int cnt=0;
  for (int j=A; j<=B; j++) {
    int i=j;
    int a1 = i/10000;
    i%=10000;
    int a2 = i/1000;
    i%=1000;
    int a3 = i/100;
    i%=100;
    int a4 = i/10;
    i%=10;
    if (a1==i && a2==a4)cnt++;
  }
  cout << cnt << endl;
  return 0;
}
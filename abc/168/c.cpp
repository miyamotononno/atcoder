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
#define PI 3.141592653589793
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int A,B,H,M;

int main() {
  INCANT;
  cin >> A >> B >> H >> M;
  double jishin = (double)360*(60*H+M)/(60*12);
  double hunshin = (double)360*M/60;
  double w = max(360-abs(hunshin-jishin), abs(hunshin-jishin));
  double ans = pow(A,2)+pow(B,2)-2*A*B*cos(PI*(w/180.0));
  cout << sqrt(ans) << "\n";
  return 0;
}
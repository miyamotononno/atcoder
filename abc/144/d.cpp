#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
double a,b,x;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> a >> b >> x;
  if (x > b*pow(a,2)/2) {
    double c = 2*(a*b-x/a) / pow(a,2);
    cout << setprecision(10) <<  atan(c) * 180/PI << "\n";
  } else {
    double c = pow(b,2)*a/(2*x);
    cout << setprecision(10) << atan(c) * 180/PI << "\n";
  }

  return 0;
}
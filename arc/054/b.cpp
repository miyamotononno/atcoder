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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(10);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
long double a;

long double func(long double x) {
  return 1.0+a*pow(2, -x/1.5)*log(2)/(-1.5);
}

int main() {
  INCANT;
  cin >> a;
  long double l = 0.0, r=100.0;
  while(r-l>0.000000001) {
    long double mid = (l+r)/2.0;
    if (func(mid)>0.0) r= mid;
    else l = mid;
  }
  
  cout << l + a/(pow(2, l/1.5))<< "\n";
  return 0;
}
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
int n, m;
double A[1001], B[1001], C[101], D[101];

bool check(double X) {
  vector<double> vec;
  rep(i, n) vec.push_back(B[i]-X*A[i]);
  sort(ALL(vec), greater<double>());
  double comp = 0.0;
  rep(i, 5) comp+=vec[i];
  if (comp>=0.0) return true;
  double helper = -1000000.0;
  rep(i, m) helper = max(helper, D[i]-X*C[i]);
  
  return (comp+helper-vec[4]>=0.0);
}

int main() {
  INCANT;
  cin >> n >> m;
  double ng = 0.0;
  rep(i, n) {
    cin >> A[i] >> B[i];
    ng = max(ng, B[i]/A[i]);
  }
  rep(i, m) {
    cin >> C[i] >> D[i];
    ng = max(ng, D[i]/C[i]);
  }
  ng+=1.0;
  double ok = 0.0;
  while(ng-ok>1e-6) {
    double mid = (ng+ok)/2.0;
    if (check(mid)) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
  return 0;
}
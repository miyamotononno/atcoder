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
const int INF = 2e9;
int A, B, W;

int main() {
  INCANT;
  cin >> A >> B >> W;
  W*=1000;
  if (A==B) {
    if (W%A==0) {
      cout << W/A << ' ' << W/A << endl;
    } else {
      cout << "UNSATISFIABLE" << endl;
    }
    return 0;
  }

  if (W%A>0 && W%B>0 && W/A==W/B) {
    cout << "UNSATISFIABLE" << endl;
    return 0;
  }

  int mx = W/A;
  int mn = W%B==0?W/B:W/B+1;

  if (mx==-1) {
    cout << "UNSATISFIABLE" << endl;
  } else {
    cout << mn << ' ' <<  mx << endl;
  }
  return 0;
}
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
int A,B,C,X;

int main() {
  INCANT;
  cin >> A >> B >> C>> X;
  int res=0;
  rep(i, A+1) {
    rep(j, B+1) {
      rep(k, C+1) {
        if (X == i*500+j*100+k*50) res++;
      }
    }
  }
  cout << res << "\n";
  return 0;
}
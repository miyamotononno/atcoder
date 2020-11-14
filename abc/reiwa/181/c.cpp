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
int N;
struct P{int x,y;};
P A[101];

bool calc(P p1, P p2, P p3) {
  if (p1.x == p2.x) return p3.x == p1.x;
  if (p1.y == p2.y) return p3.y == p1.y;
  int left = p3.y*(p2.x-p1.x);
  int right = (p2.y-p1.y)*(p3.x-p1.x)+p1.y*(p2.x-p1.x);
  return left == right;
}

int main() {
  INCANT;
  cin >> N;
  int x,y;
  rep(i, N) {
    cin >> x >> y;
    P p = {x,y};
    A[i] = p;
  }
  
  rep(i, N-2) {
    for (int j=i+1; j<N-1; j++) {
      for (int k=j+1; k<N; k++) {
        if (calc(A[i], A[j], A[k])) {
          cout << "Yes" << "\n";
          return 0;
        }
      } 
    }
  }

  cout << "No" << "\n";
  return 0;
}
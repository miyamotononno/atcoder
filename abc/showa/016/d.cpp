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
const int INF = 2e9;
double ax,ay,bx,by, N;
double D[101][2];
typedef pair<double, double> P;
double M[2][2];
double V[2];

// A -> A^-1
bool m_inverse() {
  double a = M[0][0];
  double b = M[0][1];
  double c = M[1][0];
  double d = M[1][1];
  double keisu = a*d-b*c;
  if (!keisu) return true;
  M[0][0]=d/keisu;
  M[1][0]/=(-keisu);
  M[0][1]/=(-keisu);
  M[1][1]=a/keisu;
  return false;
} 

double m_prodcut() { // x座標だけ
  return M[0][0]*V[0]+M[0][1]*V[1];
}

double slope(P p1, P p2) {
  if (p1.first==p2.first) return 1000000.0;
  return (p1.second-p2.second)/(p1.first-p2.first);
}


bool intersected(int idx) {
  int next_idx = idx==N-1?0:idx+1;
  double x1 = D[idx][0], x2 = D[next_idx][0];
  double y1 = D[idx][1], y2 = D[next_idx][1];
  if (x1==x2 && ax==bx) return false;
  double slope1 = slope(P(x1,y1), P(x2,y2));
  double slope2 = slope(P(ax,ay), P(bx, by));
  if (slope1 == slope2) return false;
  M[0][0] = slope1;
  M[0][1] = -1;
  M[1][0] = slope2;
  M[1][1] = -1;
  V[0] = slope1*x1-y1;
  V[1] = slope2*ax-ay;
  bool err = m_inverse();
  assert(!err);
  double cx = m_prodcut();
  if (x1==x2) return ((cx>ax) ^ (cx > bx));
  if (ax==bx) return ((cx>x1) ^ (cx>x2));
  return ((cx>x1) ^ (cx>x2)) && ((cx>ax) ^ (cx > bx));
}

int main() {
  INCANT;
  cin >> ax >> ay >> bx >> by;
  cin >> N;
  rep(i, N) rep(j,2) cin >> D[i][j];
  int cnt=0;
  rep(i, N) cnt+=intersected(i);
  cout << (cnt+2)/2 << "\n";
  return 0;
}
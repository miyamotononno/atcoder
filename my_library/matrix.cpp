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
typedef long long ll;
using namespace std;
typedef pair<double, double> P;

// 二次形式の行列
// 直線の交点を求める時に使う

bool m_inverse(double M[2][2]) {
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

// MB=X
P product(double M[2][2], double B[2]) {
  double x = M[0][0]*B[0]+M[0][1]*B[1];
  double y = M[1][0]*B[0]+M[1][1]*B[1];
  return P(x,y);
}

bool slope(P p1, P p2, double &X) {
  X=100000000.0;
  if (p1.first==p2.first) return false; // 傾き無限大
  X = (p1.second-p2.second)/(p1.first-p2.first);
  return true;
}

// 2直線の交点を求める
// 点p1,p2を結ぶ直線, 点q1,q2を結ぶ直線の交点
// MX=A => X=M^(-1)*Aを使って求める
bool solve(P p1, P p2, P q1, P q2, P &X) {
  double slope1, slope2;
  bool has_slope1 = slope(p1,p2, slope1);
  bool has_slope2 = slope(q1,q2, slope2);
  if (slope1==slope2) return false; // 平行
  if (!has_slope1) {
    double x = p1.first;
    double y = slope2*(x - q1.first)+q2.first;
    X = P(x,y);
  } else if (!has_slope2) {
    double x = q1.first;
    double y = slope2*(x - p1.first)+p2.first;
    X = P(x,y);
  } else {
    double M[2][2], V[2];
    M[0][0] = slope1;
    M[0][1] = -1;
    M[1][0] = slope2;
    M[1][1] = -1;
    V[0] = slope1*p1.first-p1.first;
    V[1] = slope2*q1.first-q2.first;
    bool err = m_inverse(M);
    assert(!err);
    X = product(M, V);
  }
  return true;
}

int main() {
  INCANT;
  double p1x,p1y,p2x,p2y;
  double q1x,q1y,q2x,q2y;
  P p1(0.0, 0.0);
  P p2(1.0, 1.0);
  P q1(0.0, 1.0);
  P q2(1.0, 0.0);
  double x,y;
  P X(x,y);
  if (solve(p1,p2,q1,q2,X)) {
    cout << X.first << ' ' << X.second << "\n";
  } else {
    cout << "平行のため交点なし" << "\n";
  }
  return 0;
}
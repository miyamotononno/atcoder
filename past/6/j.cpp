#include <bits/stdc++.h>
using namespace std;
const double err = 1e-9;


double calc(const int& n, const vector<double>& A, const double& p) {
  double ret=0.0;
  for (int i=0; i<n; i++) {
    ret+=(A[i]-p)*(A[i]-p);
  }
  return ret;
}

// 三分探索
double ternarySearch(const int& n, const vector<double>& A, double lft, double rgt) {
  double costLft, costRgt;
  while (rgt - lft >= err) {
    costLft = costRgt = 0.0;
    double lftP = (2*lft+rgt)/3.0;
    double rgtP = (lft+2*rgt)/3.0;
    costLft = calc(n, A, lftP);
    costRgt = calc(n, A, rgtP);
    if (costLft > costRgt) {
      lft = lftP;
    } else {
      rgt = rgtP;
    }
  }
  return costLft;
}

int main() {
  int n;
  double c;
  cin >> n >> c;
  vector<double> X(n),Y(n);
  for (int i=0;i<n;i++) cin >> X[i] >> Y[i];
  double retY = calc(n, Y, c);

  sort(X.begin(), X.end());
  double retX = ternarySearch(n, X, X[0], X[X.size()-1]);
  cout.precision(20);
  cout << retX+retY << endl;
}
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
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const int INF = 2e9;
double n;
double x,y,xn2,yn2;
double rM[2][2];
double xy[2];

int main() {
  INCANT;
  cin >> n;
  cin >> x >> y >> xn2 >> yn2;
  
  // 中心
  double cX = (x+xn2)/2.0;
  double cY = (y+yn2)/2.0;
  xy[0] = x-cX;
  xy[1] = y-cY;
  // 角度
  double rad = 2.0*PI/n;
  rM[0][0] = cos(rad);
  rM[0][1] = - sin(rad);
  rM[1][0] = sin(rad);
  rM[1][1] = cos(rad);
  
  double ansx=0.0;
  double ansy=0.0;
  rep(i, 2) ansx+=rM[0][i]*xy[i];
  rep(i, 2) ansy+=rM[1][i]*xy[i];
  cout << ansx+cX << ' ' << ansy+cY<< "\n";
  return 0;
}
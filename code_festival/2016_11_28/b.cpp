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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  double x1,y1,x2,y2,x3,y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  double a = hypot(x1-x2,y1-y2);
  double b = hypot(x2-x3,y2-y3);
  double c = hypot(x3-x1,y3-y1);

  // ヘロンの公式
  double s = (a+b+c)/2;
  double area = sqrt(s*(s-a)*(s-b)*(s-c));

  //　内接円の半径
  double r = area/s;
  double mx = max(a, max(b,c));

  // 二分探索
  bool flag=true;
  double ans=0.0, ng = mx; 
  while(flag){
    double x = (ans+ng)/2.0;
    if (ng-ans<1e-10) flag=false;
    if (mx*(r-x) >= 2*x*r) ans=x;
    else ng=x;
  }
  cout << fixed << setprecision(10) << ans << "\n";
  return 0;
}
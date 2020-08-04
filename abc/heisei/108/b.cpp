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
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
using namespace std;
int x1,ya,x2,y2;
typedef pair<int, int> P;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> x1 >> ya >> x2 >> y2;
  P direction = make_pair(x2-x1, y2-ya);
  int x3 = x2 - direction.second;
  int y3 = y2 + direction.first;
  int x4 = x1 - direction.second;
  int y4 = ya + direction.first;

  cout << x3 << ' '<< y3 << ' ' << x4 << ' ' << y4 << "\n";
  
  return 0;
}
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
typedef long long ll;
using namespace std;
int K, X, Y;
bool x_flag, y_flag; 
struct edge {int x, y; };

void bfs(int )

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> K >> X >> Y;
  if ((X+Y)%2==1 && K%2 == 0){
    cout << -1 <<endl;
    return 0;
  }
  
  if (X<0){
    x_flag = true;
    X*= -1;
  }
  if (Y<0){
    y_flag = true;
    Y*= -1;
  }

  vector<vector<int> > Ans; 

  int x_p = 0; 
  int y_p = 0;
  while (X - x_p > K || Y - y_p > K) {
    if (X - x_p > K ){
      edge e = {x_p+K, y_p};
      x_p += K;
      Ans.push_back(e);
      continue;
    }
    if (y_p > K) {
      edge e = {x_p, y_p+K};
      y_p += K;
      Ans.push_back(e);
      continue;
    }
  }
  int K1 = K;
  K1 -= (X- x_p);
  y_p+=K1;
  edge e = {X- x_p, y_p};
  Ans.push_back(e);
  if (y_p+K == Y){
    edge e = {X, Y};
    Ans.push_back(e);
    return 0;
  } else{
    if ((Y - y_p)%2==0){
      int rest = (Y - y_p)/2;
      edge e1 = {X+K-rest, y_p+rest};
      Ans.push_back(e1);
      edge e2 = {X, Y};
      Ans.push_back(e2);
    } else return 0;
  }

  cout << Ans.size() << endl;
  rep(i, Ans.size()){
    edge e = Ans[i];
    int x = e.x;
    int y = e.y;
    if (x_flag) x*=-1;
    if (y_flag) y*=-1;
    cout << x <<' '<< y <<endl;
  }
  return 0;
}
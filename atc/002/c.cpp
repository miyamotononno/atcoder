#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <utility>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
using namespace std;
const int INF = 1000000000;
typedef pair<int, int> P;
char maze[50][50];
int R, C; // Rがy座標, Cがx座標
int d[50][50];
int sx, sy, gx, gy;
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
 
int bfs(){
  queue<P> que;
  for (int i=0; i<R;i++)
    for(int j=0; j<C; j++) d[i][j] = INF;

  que.push(P(sy, sx));
  d[sy][sx] = 0;
  
  while(que.size()){
   P p = que.front(); que.pop();
    if (p.first == gy && p.second == gx) break;
    for (int i=0; i<4; i++){
      int ny=p.first + dy[i], nx = p.second + dx[i];
      if (nx>=0 && nx<C && ny>=0 && ny<R && maze[ny][nx] != '#' && d[ny][nx] == INF){
        que.push(P(ny, nx));
        d[ny][nx] = d[p.first][p.second] + 1;
      }
    }
  }
  return d[gy][gx];
}
 
 
 
int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> R >> C >> sy >> sx >> gy >> gx;
  sy--; sx--; gy--; gx--;
  for (int i=0; i<R;i++){
    for(int j=0; j<C; j++){
      cin >> maze[i][j];
    }
  }
  
  int res = bfs();
  cout << res << endl; 
  
}

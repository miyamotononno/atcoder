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
typedef long long ll;
using namespace std;
bool visited[500][500];
int maze[500][500];
int H, W;

void search(int h, int w){
  visited[h][w] = true;
  if (h+1 < H && maze[h+1][w] == '.' && !visited[h+1][w]){
    search(h+1, w);
  }
  if(h > 0 && maze[h-1][w] == '.' && !visited[h-1][w]){
    search(h-1, w);
  }
  if(w > 0 && maze[h][w-1] == '.' && !visited[h][w-1]){
    search(h, w-1);
  }
  if(w+1 < W && maze[h][w+1] == '.' && !visited[h][w+1]){
    search(h, w+1);
  }
}

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> H >> W;
  int sh, sw, gh, gw;
  char a;
  for(int i=0;i<H; i++){
     for(int j =0; j<W; j++){
       cin >> a;
       if (a=='s'){
         sh = i;
         sw = j;
         maze[i][j] = '.';
       }else if(a=='g'){
         gh = i;
         gw = j;
         maze[i][j] = '.';
       }else{
         maze[i][j] = a;
       }
     }
  }
  
  search(sh, sw);
  if (visited[gh][gw]){
    cout << "Yes";
  }else{
    cout << "No";
  }

  return 0;
}

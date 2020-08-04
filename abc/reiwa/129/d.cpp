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
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
int H, W;
bool b[2005][2005];
int L[2005][2005], R[2005][2005], D[2005][2005], U[2005][2005];  

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> H >> W;

  rep(i,H){
    string s;
    cin >> s;
    rep(j,W){
      if (s[j] == '.') {
         b[i][j] = true;
      }
    }
  }
   
  rep(i,H) {
    rep(j,W) {
      if (!b[i][j]) continue;
      if (j==0){
        L[i][j] = 1;
      }else{
        L[i][j] = L[i][j-1] + 1;
      }
    }
    rep_down(j, W){
      if (!b[i][j]) continue;
      if (j==W){
        R[i][j] = 1;
      }else{
        R[i][j] = R[i][j+1] + 1;
      }
    }
  }


  rep(j,W){
    rep(i,H) {
      if (!b[i][j]) continue;
      if (i==0){
        D[i][j] = 1;
      }else{
        D[i][j] = D[i-1][j] + 1;
      }
    }
    rep_down(i, H){
      if (!b[i][j]) continue;
      if (i==H){
        U[i][j] = 1;
      }else{
        U[i][j] = U[i+1][j] + 1;
      }
    }
  }

  int ans = 0;
  rep(i,H){
    rep(j,W){
      if (!b[i][j]) continue;
      ans = max(ans, L[i][j]+R[i][j]+D[i][j]+U[i][j] -3);
    }
  }

  
  cout << ans << endl;
  return 0;
}
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
typedef long long ll;
using namespace std;
int A, B, C, D, E, F;
double DP[3005][3005]; // 水、砂糖

double dfs(int water, int sugar){ // 水の量(100の倍数)、砂糖の量
  if (DP[water][sugar]>0) return DP[water][sugar];
  double res = water>0?(double)sugar/(water+sugar):0.0;
  DP[water][sugar] = res;
  rep(i, 4){
    if (i==0){
      if (water+sugar+100*A <= F) res = max(dfs(water+100*A, sugar), res);
    } else if (i==1){
      if (water+sugar+100*B <= F) res = max(dfs(water+100*B, sugar), res);
    } else if (i==2){
      if (water+sugar+C<=F && (sugar+C)*100 <=E*water) res = max(dfs(water, sugar+C), res);
    } else {
      if (water+sugar+D<=F && (sugar+D)*100 <= E*water) res = max(dfs(water, sugar+D), res);      
    }
  }
  return res;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B >> C >> D >> E >> F;
  double ans = dfs(0, 0);
  for (int i=100*A; i<=F; i+=100){
    for (int j=0; j<=F-i; j++){
      if (DP[i][j]==ans){
        cout << i+j << ' ' << j << "\n";
        return 0;
      }
    }
  }
  return 0;
}
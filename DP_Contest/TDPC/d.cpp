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
#include <functional>
#include <map>
typedef long long ll;
#define rep(i,n) for (int i=0; i<n;++i)
using namespace std;
ll N,D;
int F[3] = {}; 
int v[3] = {2,3,5};
int d2[6] = {0,1,0,2,0,1}, d3[6] = {0,0,1,0,0,1}, d5[6] = {0,0,0,0,1,0};

bool factoring(ll d){
    rep(i,3){
        int cnt = 0;
        while(d%v[i] == 0){
            d/=v[i];
            cnt++;
        }
        F[i] = cnt;
    }
    return d>1;
}

int main(){
  cin >> N >> D;
  if(factoring(D)){
      cout << 0 << endl;
      return 0;
  }

  vector<vector<vector<double> > > dp(F[0]+1, vector<vector<double> >(F[1]+1, vector<double>(F[2]+1)));
  dp[0][0][0] = 1.0;

  rep(_, N){
    vector<vector<vector<double> > > next(F[0]+1, vector<vector<double> >(F[1]+1, vector<double>(F[2]+1)));
    rep(i, F[0]+1){
        rep(j, F[1]+1){
            rep(k, F[2]+1){
                rep(s, 6){
                    int n2 = min(F[0], i+d2[s]);
                    int n3 = min(F[1], j+d3[s]);
                    int n5 = min(F[2], k+d5[s]);
                    next[n2][n3][n5] += dp[i][j][k]/6.0;
                }
            }
        }
    }
    dp.swap(next);
  }

  cout << dp[F[0]][F[1]][F[2]] << endl;
}

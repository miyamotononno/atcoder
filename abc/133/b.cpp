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
const ll MOD = 1000000007LL;
int N, D;
int X[11][11];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> D;
    rep(i,N){
      rep(j,D){
        cin >> X[i][j];
      }
    }

    int cnt = 0;
    rep(i, N){
      for(int j=i+1; j<N; j++){
        int sm = 0;
        rep(k, D){
          sm+= pow(X[i][k]-X[j][k], 2);
        }
        int n =0;
        int l =0;
        while(n<=sm){
          if (n==sm){
            cnt++;
            break;
          }
          l++;
          n=pow(l,2);
        }
      }
    }

    cout << cnt << endl;
    return 0;
}
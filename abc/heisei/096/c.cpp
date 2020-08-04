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
int H, W;
char s[52][52];
int dh[4] = {-1, 0, 1, 0};
int dw[4] = {0, 1, 0, -1}; 

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W;
    rep(i, H){
      rep(j, W) cin >> s[i][j];
    }
    rep(i, H){
      rep(j, W){
        if (s[i][j] == '.') continue;
        bool flag = true;
        rep(l, 4){
          if (i==0 && l==0) continue;
          if (j==W-1 && l==1) continue;
          if (i==H-1 && l==2) continue;
          if (j==0 && l==3) continue;
          if (s[i+dh[l]][j+dw[l]] == '#') {
            flag = false;
          };
        }
        if (flag){
          cout << "No" << endl;
          return 0;
        }
      }
    }

    cout << "Yes" << endl;
    return 0;
}
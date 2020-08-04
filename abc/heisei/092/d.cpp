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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
int A, B;
char Ans[100][100];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B;

  rep(i, 50){
    rep(j, 100) Ans[i][j] = '.'; 
  }
  for(int i=50; i < 100; i++){
    rep(j, 100) Ans[i][j] = '#';
  }

  int b_cnt = 0;
  int h = 0;
  int w = 0;
  if (B > 1){
    while(b_cnt < B-1){
      Ans[h][w] = '#';
      b_cnt++;
      w+=2;
      if (w>=100){
        h+=2;
        w=0;
      }
    }
  }

  h = 51;
  w = 0;
  int w_cnt = 0;
  if (A>1){
    while(w_cnt < A-1){
      Ans[h][w] = '.';
      w_cnt++;
      w+=2;
      if (w>=100){
        h+=2;
        w = 0;
      }
    }  
  }

  cout << 100 << ' ' << 100 << endl;

  rep(i,100){
    rep(j, 100){
      cout << Ans[i][j];
    }
    cout << endl;
  }

  return 0;
}
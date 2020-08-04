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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
int N;
typedef pair<int, pair<int, int> > P;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  vector<P> Z(N);
  int a,b,c;
  rep(i, N){
    cin >> a >> b >> c;
    P p = make_pair(c, make_pair(a, b));
    Z[i] = p;
  }
  sort(Z.begin(), Z.end(), greater<P>());

  rep_down(i, 101){ // x座標
    rep_down(j, 101){ // y座標
      int max_h = abs(i - Z[0].second.first)+abs(j-Z[0].second.second)+Z[0].first;
      bool flag = true;
      for (int k=1; k<N; k++){
        int h = Z[k].first;
        int x = Z[k].second.first;
        int y = Z[k].second.second;
        if (h==0){
          if (max_h > abs(i-x)+abs(j-y)){
            flag = false;
            break;
          }
        }else{
          if (max_h!=abs(i-x)+abs(j-y)+h){
            flag = false;
            break;
          }
        }
      }
      if (flag){
        cout << i << ' ' << j << ' ' << max_h << "\n";
        return 0;
      }
    }
  }
  return 0;
}

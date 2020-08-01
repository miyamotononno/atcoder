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
const int INF = 1000000007;
int N, M;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  int ad = 0;
  int od = 0;
  // 赤ちゃんの足はN-(a+b)
  if (4*N-M<0) {
    cout << "-1 -1 -1" <<endl;
    return 0;
  }
  while(4*N-M-od >=0){
    if ((4*N-M-od)%2==0){
      ad = (4*N-M-od)/2;
      if (N- ad-od >=0){
        cout << ad << ' ' << od << ' ' << N- ad-od <<endl;
        return 0;
      }
    }
    od++;
  }


  cout << "-1 -1 -1" <<endl;
  return 0;
  return 0;
}
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
const int MAX_V = 100000;
int d[MAX_V][MAX_V]; //d[u][v]は辺e = (u, v)のコスト。存在しない場合はINF,ただしd[i][j]=0とする。
int V;

void warshall_floyd() {
  rep(k, V){
    rep(i, V){
      rep(j, V) d[i][j] =min(d[i][j], d[i][k]+d[k][j]);
    }
  }
}
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
int N, K;
vector<int> G[101];

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;

  rep(i, N-1){
    G[0].push_back(i+1);
  }
  int r = ((N-1)*(N-2))/2 - K;
  if (r < 0){
    cout << -1 << endl;
    return 0;
  }
  int cnt = 1;
  while(r>0){
    for(int i=cnt+1; i< N; i++){
      G[cnt].push_back(i);
      r--;
      if (r==0) break;
    }
    cnt++; 
  }

  cout << (N*(N-1))/2 - K << endl;
  rep(i, N){
    if (G[i].size() == 0) break;
    rep(j, G[i].size()){
      int t = G[i][j];
      cout << i+1 << ' ' << t +1 << endl;
    }
  }

}
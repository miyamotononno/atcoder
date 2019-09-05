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
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N, M;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  vector<int> Mp[N];

  int a, b;
  rep(i, M){
    cin >> a >> b;
    a--;b--;
    Mp[a].push_back(b);
    Mp[b].push_back(a);    
  }

  rep(i, N){ // 自分
    vector<bool> P(N, false);
    rep(j, Mp[i].size()){ // 友達
      int fr = Mp[i][j];
      rep(k, Mp[fr].size()){ // 友達の友達
        int fr_fr = Mp[fr][k];
        P[fr_fr] = true;
      }
    }
    rep(j, Mp[i].size()){
      int fr = Mp[i][j];
      P[fr] = false;
    }
    P[i] = false;
    int cnt = 0;
    rep(i, N) cnt += P[i]?1:0;
    cout << cnt << "\n";
  }
  return 0;
}
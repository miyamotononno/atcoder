#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, X, Y;
vector<int> G[2003];
int S[2003];
int Cnt[2003]; // idx長さの個数
typedef pair<int, int> P;

void bfs() {
  int no_kiroku = -1; 
}

int main() {
  INCANT;
  cin >> N >> X >> Y;
  X--;Y--;
  rep(i, N) {
    if (i==X) G[i].push_back(Y);
    if (i==Y) G[i].push_back(X);
    if (i<N-1) G[i].push_back(i+1);
    if (i>0) G[i].push_back(i-1);
  }
  int no_kiroku = -1;
  rep(i, N-1) {
    rep(j, N) S[j]=-1;
    queue<P> que;
    que.push(P(i, 0));
    while (!que.empty()) {
      P p = que.front(); que.pop();
      if (S[p.first] >=0) continue;
      S[p.first] = p.second;
      if (p.first > no_kiroku) {
        Cnt[p.second]++;
      }
      for(auto ne: G[p.first]) {
        if (S[ne]<0) {
          que.push(P(ne, p.second+1));
        }
      }
    }
    no_kiroku =  i;
  }
  rep(i, N-1) cout << Cnt[i+1] << "\n";
  return 0;
}
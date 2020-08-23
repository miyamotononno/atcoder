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
#define index_of(as, x) distance(as.begin(), lower_bound(as.begin(), as.end(), x))
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
typedef pair<int,int> P;
int H, W, M;
int row[300005],col[300005]; 
vector<int> G[300005];

vector<P> get_max(vector<P> &A) {
  vector<P> ret;
  int mx = A[0].first;
  int idx=0;
  while(mx==A[idx].first && idx < A.size()) {
    ret.push_back(A[idx]);
    idx++;
  }
  return ret;
} 

int main() {
  INCANT;
  cin >> H >> W >> M;
  int h, w;
  rep(i, M) {
    cin >> h >> w;
    h--;w--;
    row[h]++;
    col[w]++;
    G[h].push_back(w);
  }
  vector<P> rcnt(H), ccnt(W);
  rep(i, H) rcnt[i]=P(row[i], i);
  sort(ALL(rcnt), greater<P>());
  rep(i, W) ccnt[i]=P(col[i], i);
  sort(ALL(ccnt), greater<P>());
  vector<P> rkouho = get_max(rcnt);
  vector<P> ckouho = get_max(ccnt);
  int MAX = rcnt[0].first+ccnt[0].first;
  for (auto rp: rkouho) {
    int r=rp.second;
    vector<int> vec = G[r];
    sort(ALL(vec));
    for (auto cp: ckouho) {
      int c=cp.second;
      int id = index_of(vec, c);
      if (vec[id]==c) continue;
      cout << MAX << endl;
      return 0;
    }
  }
  cout << MAX-1 << endl;
  
  return 0;
}
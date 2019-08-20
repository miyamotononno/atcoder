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
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N, M;
typedef pair<int, pair<int, int> > P;
unordered_map<int, int> Mp;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  int p, y;
  vector<P> L(M);
  rep(i, M){
    cin >> p >> y;
    P pr = make_pair(y, make_pair(p, i));
    L[i]=pr;
  }

  sort(L.begin(), L.end());
  vector<P> Ans(M);
  rep(i, M){
    int p = L[i].second.first;
    Mp[p] += 1;
    P pr = make_pair(L[i].second.second, make_pair(Mp[p], p));
    Ans[i] =  pr;
  }
  sort(Ans.begin(), Ans.end());
  rep(i, M){
    int idx = Ans[i].second.first;
    int p = Ans[i].second.second;
    cout << setfill('0') << right << setw(6) << p;
    cout << setfill('0') << right << setw(6) << idx << endl;
  }

  return 0;
}


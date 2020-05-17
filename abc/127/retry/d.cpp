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
int N, M;
typedef pair<int, int> P;
P D[100005];
priority_queue<int, vector<int>, greater<int> > que;

int main() {
  INCANT;
  cin >> N >> M;
  int x;
  rep(i, N) {
    cin >> x;
    que.push(x);
  }
  int a,b;
  rep(i, M) {
    cin >> a >> b;
    D[i]= P(b,a);
  }
  sort(D, D+M, greater<P>());
  int idx=0;
  ll SUM=0;
  while(!que.empty()) {
    int q = que.top(); que.pop();
    if (D[idx].first<=q || idx==M) SUM+=(ll)q;
    else {
      SUM+=(ll)D[idx].first;
      D[idx].second = D[idx].second-1;
      if (D[idx].second==0) idx++;
    }
  }

  cout << SUM << "\n";
  return 0;
}
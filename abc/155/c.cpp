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
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
unordered_map<string, int> T;
typedef pair<int, string> P;
vector<P> Q;
vector<string> Q2;
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  string S;
  rep(i, N) {
    cin >> S;
    T[S] += 1;
  }
  for (auto it=T.begin(); it !=T.end(); ++it){
    string c = it->first;
    int v = it->second;
    Q.push_back(P(v, c));
  }
  sort(ALL(Q), greater<P>());
  int count = Q[0].first;
  rep(i, Q.size()) {
    if (count!=Q[i].first) break;
    Q2.push_back(Q[i].second);
  }
  sort(ALL(Q2));
  rep(i, Q2.size()) cout << Q2[i] << "\n";
  return 0;
}
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
string S,T;
unordered_map<char, int> M;
unordered_map<char, vector<ll> > N;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S >> T;
  rep(i, S.size()){
    M[S[i]]++;
    N[S[i]].push_back(i);
  }

  rep(i, T.size()){
    char t = T[i];
    if (M[t]==0){
      cout << -1 << endl;
      return 0;
    }
  }
  ll current = -1ll;
  ll counter = 0ll;
  rep(i, T.size()){
    char c = T[i];
    vector<ll>::iterator it = upper_bound(N[c].begin(), N[c].end(), current);
    if (it == N[c].end()){
      counter++;
      current = N[c][0];
    } else current = *it;
  }
  cout << counter*S.size()+current+1ll << endl;
  return 0;
}
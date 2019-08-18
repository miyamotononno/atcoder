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
    char s = T[i];
    if (M[s]==0){
      cout << -1 << endl;
      return 0;
    }
  }
  ll l = S.size();
  ll ans = 0ll;
  ll counter = 0ll;
  rep(i, T.size()){
    char c = T[i];
    bool flag = false;
    rep(j, N[c].size()){
      if (ans < N[c][j] && N[c][j] < (counter+1)*l){
        ans += N[c][j];
        N[c][j]+=l;
        flag = true; 
        break;
      }
      N[c][j]+=l;
    }
    if (flag) continue;
    counter+=1ll;
    ans = N[c][0];
    N[c][0]+=l;
  }
  cout << ans+1 << endl;
  return 0;
}
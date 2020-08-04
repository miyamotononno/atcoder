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
int N;
string S[100001];
unordered_map<string, ll> M;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  string s;
  rep(i, N){
    cin >> s;
    sort(s.begin(), s.end());
    S[i] = s;
    if (M.count(s)>0){
      M[s] += 1ll;
    } else{
      M[s]= 1ll;
    }
  }

  ll cnt = 0ll;

  for (auto it=M.begin(); it !=M.end(); ++it){
    ll v = it->second;
    cnt += (v*(v-1))/2;
  }

  cout << cnt << endl;
  return 0;
}
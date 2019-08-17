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
int N;
string S;
unordered_map<char, ll> M;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  cin >> S;
  rep(i, N){
   char s = S[i];
   if (M.count(s) > 0){
     M[s]+=1ll;
   } else {
     M[s]=1ll;
   }
  }

  ll cnt = 1ll;

  for (auto it=M.begin(); it !=M.end(); ++it){
    ll v = it->second;
    cnt*=(v+1);
    cnt %= MOD;
  }
  cnt+=MOD-1;
  cnt%=MOD;
  cout << cnt << endl;
  return 0;
}

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
int N;
string S;
vector<int> R,G,B;

char rest(char a, char b) {
  if ((a=='R' && b =='G') || (a=='G' && b =='R')) return 'B';
  else if ((a=='B' && b =='G') || (a=='G' && b =='B')) return 'R';
  else if ((a=='B' && b =='R') || (a=='R' && b =='B')) return 'G';
  return ' ';
}

int main() {
  INCANT;
  cin >> N;
  cin >> S;
  rep(i, N) {
    if (S[i]=='R') R.push_back(i);
    if (S[i]=='G') G.push_back(i);
    if (S[i]=='B') B.push_back(i);
  }
  ll ans = 0;
  rep(i, N-2) {
    for (int j=i+1; j<N-1; j++) {
      if (S[i]==S[j]) continue;
      char c = rest(S[i], S[j]);
      int ng = 2*j-i;
      int cnt=0;
      if (c=='R') {
        cnt =upper_bound(ALL(R), j)-R.begin();
        ans+=R.size()-cnt;
      } else if (c=='G') {
        cnt =upper_bound(ALL(G), j)-G.begin();
        ans+=G.size()-cnt;
      }else {
        cnt =upper_bound(ALL(B), j)-B.begin();
        ans+=B.size()-cnt;
      }
      if (ng<N && S[ng]==c) ans--;
      
    }
  }

  cout << ans << "\n";

  return 0;
}

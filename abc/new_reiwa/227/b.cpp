#include <bits/stdc++.h>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n;

int main() {
  INCANT;
  cin >> n;
  int S[n];
  rep(i,n) cin >> S[i];
  int cnt=0;
  rep(c, n) {
    bool flag = true;
    rep(i, 1000) {
      int a=i+1;
      rep(j, 1000) {
        int b=j+1;
        if (4*a*b+3*a+3*b == S[c]) {
          flag = false;
          break;
        }
      }
      if (!flag) break;
    }
    if (flag) cnt++;
  }
  cout << cnt << "\n";
  return 0;
}
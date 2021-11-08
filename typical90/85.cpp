#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll K;
  cin >> K;
  ll ret=0ll;
  for (ll a=1ll; a*a*a<=K; a++) {
    if (K%a!=0) continue;
    for (ll b=a; a*b*b<=K; b++) {
      if (K%(a*b)==0) {
        ret++;
      }
    }
  }
  cout << ret << endl;
}
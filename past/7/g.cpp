#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solve(ll n) {
  vector<ll> ret;
  ll cur = 1ll;
  while(n>0) {
    switch(n%3) {
      case 1: {
        ret.push_back(cur);
        n-=1ll;
        break;
      }
      case 2: {
        ret.push_back(-cur);
        n+=2ll;
        break;
      }
    }
    n/=3ll;
    cur*=3ll;
  }
  return ret;
}

int main() {
  ll N;
  cin >> N;
  vector<ll> ret = solve(N);
  int m=ret.size();
  cout << m << endl;
  for (int i=0; i<m; i++) {
    cout << ret[i] << (i==m-1?"\n":" ");
  }
}
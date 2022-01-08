#include <bits/stdc++.h>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
ll K;

// https://cpprefjp.github.io/reference/algorithm/reverse.html


string solve(const ll& k) {
  ll d = k;
  string str = "";
  while(d>0) {
    if (d%2==1) str+='2';
    else str += '0';
    d/=2ll;
  }
  reverse(str.begin(), str.end());
  return str;
}

int main() {
  cin >> K;
  cout << solve(K) << "\n";
}
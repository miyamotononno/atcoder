#include <bits/stdc++.h>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;

void solve(const int& n, const int& k, const vector<int>& P) {
  priority_queue<int, vector<int>, greater<int>> pque;
  rep(i, k) pque.push(P[i]);
  for (int i=0; i<=n-k; i++) {
    cout << pque.top() << endl;
    if (i<n-k && P[i+k]>pque.top()) {
      pque.pop();
      pque.push(P[i+k]);
    }
  }
}

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> P(n);
  rep(i, n) cin >> P[i];
  solve(n,k,P);
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  unordered_set<int> A[n];
  for (int i=0; i<n; i++) {
    int k;
    cin >> k;
    for (int j=0; j<k; j++) {
      int a;
      cin >> a;
      A[i].insert(a);
    }
  }
  int p,q;
  cin >> p >> q;
  vector<int> B(p);
  for (int i=0; i<p; i++) {
    cin >> B[i];
  }

  int ans = 0; 
  for (int i=0; i<n; i++) {
    int cnt = 0;
    for (int b: B) {
      if (A[i].find(b)!=A[i].end()) cnt++;
    }
    ans += cnt >= q?1:0;
  }
  cout << ans << endl;
  return 0;
}
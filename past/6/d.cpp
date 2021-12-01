#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n,k;
  cin >> n >> k;
  ll A[n];
  for (int i=0; i<n; i++) cin >> A[i];
  ll sumA[n+1];
  for (int i=0; i<=n; i++) {
    if (i==0) {
      sumA[i] = 0;
    } else {
      sumA[i] = sumA[i-1] + A[i-1];
    }
  }
  for (int i=0; i<n-k+1; i++) {
    cout << sumA[i+k] - sumA[i] << endl;
  }
}
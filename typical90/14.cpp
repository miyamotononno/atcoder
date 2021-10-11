#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
  int n;
  ll A[100005], B[100005];
  cin >> n;
  for (int i=0; i<n; i++) cin >> A[i];
  for (int i=0; i<n; i++) cin >> B[i];

  sort(A, A+n);
  sort(B, B+n);

  ll ans = 0ll;
  for (int i=0; i<n; i++) {
    ans+= abs(A[i]-B[i]);
  }
  cout << ans << endl;
}
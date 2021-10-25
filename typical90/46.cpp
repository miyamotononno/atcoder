#include <iostream>
#include <vector>
#include <algorithm>
int N;
int A[100003], B[100003], C[100003];
using namespace std;
typedef long long ll;
const int MOD = 46;

int main() {
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    A[i]%=MOD;
  }
  for (int i=0; i<N; i++) {
    cin >> B[i];
    B[i] %= MOD;
  }
  for (int i=0; i<N; i++) {
    cin >> C[i];
    C[i] %= MOD;
  }
  sort(A, A+N);
  sort(B, B+N);
  sort(C, C+N);
  ll ret = 0ll;
  for (int i=0; i<MOD; i++) {
    ll a_cnt = upper_bound(A, A+N, i) - lower_bound(A, A+N, i);
    if (a_cnt==0) continue;
    for (int j=0; j<MOD; j++) {
      int k = (92 - i - j) % MOD;
      ll b_cnt = upper_bound(B, B+N, j) - lower_bound(B, B+N, j);
      ll c_cnt = upper_bound(C, C+N, k) - lower_bound(C, C+N, k);
      ret += a_cnt * b_cnt * c_cnt;
    }
  }
  cout << ret << endl; 
}

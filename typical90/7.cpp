#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
#define rep(i,n) for (int i=0; i<n;++i)

int A[300002], Q, B[300002];

int main() {
  cin >> N;
  rep(i, N) cin >> A[i];
  cin >> Q;
  rep(i, Q) cin >> B[i];
  sort(A, A+N);
  rep(i, Q) {
    int val = B[i];
    int idx = lower_bound(A, A+N, val) - A;
    if(idx == N) {
      cout << abs(A[N-1] - B[i]) << endl;
    } else if (idx == 0) {
      cout << abs(A[0] - B[i]) << endl;
    } else {
      int val = min(abs(A[idx]-B[i]), abs(A[idx-1] - B[i]));
      cout << val << endl;
    }
  }
  
}
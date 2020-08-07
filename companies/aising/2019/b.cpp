using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define rep(i,n) for (int i=0; i<n;++i)
int N,A,B;
int P[101];


int main() {
  cin >> N >> A >> B;
  rep(i, N) cin >> P[i];
  sort(P, P+N);
  int k1 = lower_bound(P, P+N, A+1)-P;
  int k2 = lower_bound(P, P+N, B+1)-P;
  cout << min(min(k1, k2-k1),N-k2) << endl;
}

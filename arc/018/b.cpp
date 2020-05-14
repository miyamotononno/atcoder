#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int N;
typedef pair<ll, ll> P;
P A[101];

bool calc(P p1, P p2, P p3) {
  ll x = p3.first-p1.first;
  if (!x) return false;
  ll double_area = p1.second*(p3.first-p2.first) + p3.second*(p2.first-p1.first) - p2.second*x;
  return double_area && double_area%2==0;
}

int main() {
  INCANT;
  cin >> N;
  int a, b;
  rep(i, N) {
    cin >> a >> b;
    A[i]=P(a,b);
  }
  sort(A, A+N);
  int cnt=0;
  for (int i=0; i<N-2; i++) {
    for (int j=i+1; j<N-1; j++) {
      for (int k=j+1; k<N; k++) {
        cnt+=calc(A[i], A[j], A[k]);
      }
    }
  }

  cout << cnt << "\n";
  return 0;
}
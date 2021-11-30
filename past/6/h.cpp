#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2e18;
int N, M, K; ll Q;

int main() {
  cin >> N >> M >> K >> Q;
  vector<ll> A, B;
  for (int i=0; i<N; i++) {
    ll p; int t;
    cin >> p >> t;
    if (t==1) A.push_back(p);
    else B.push_back(p);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  vector<ll> sumA, sumB;
  sumA.push_back(0); // 1-index
  sumB.push_back(0); // 1-index
  for (auto a: A) sumA.push_back(a+sumA.back());
  for (auto b: B) sumB.push_back(b+sumB.back());

  ll ret = INF;
  for (int a=0; a<=M; a++) {
    int b = M-a;
    if (sumA.size()<=a || sumB.size() <= b) continue;
    ll retA = sumA[a];
    ll retB = sumB[b];
    ll canOpenerCnt = (a+K-1) / K;
    ll canOpenerSum = canOpenerCnt*Q;
    ret = min(ret, sumA[a]+sumB[b]+canOpenerSum);
  }
  cout << ret << endl;
} 
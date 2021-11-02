#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;

ll distance(ll a[], ll& point) {
  ll ret = 0ll;
  for (int i=0; i<N; i++) {
    ret+=abs(a[i]-point);
  }
  return ret;
}

ll calcMinManhatttan(ll x[], ll y[]) {
  sort(x, x+N);
  sort(y, y+N);
  ll middleX = x[N/2];
  ll middleY = y[N/2];
  return distance(x, middleX) + distance(y, middleY);
}

int main() {
  cin >> N;
  ll X[N], Y[N];
  for (int i=0; i<N; i++) cin >> X[i] >> Y[i];
  cout << calcMinManhatttan(X, Y) << endl;
}
#include <bits/stdc++.h>
using namespace std;

/*
generate関数
https://cpprefjp.github.io/reference/algorithm/generate.html
*/

void solve(const int& n, const int& m, int a[], int outputs[]) {
  int maxSushi[n];
  generate(maxSushi, maxSushi+n, [](){return 0;});
  for (int i=0; i<m; i++) {
    int idx = upper_bound(maxSushi, maxSushi+n, -a[i]) - maxSushi;
    if (idx == n) {
      outputs[i] = -1;
      continue;
    }
    maxSushi[idx] = -a[i];
    outputs[i] = idx+1;
  }
  return;
}

int main() {
  int N, M;
  cin >> N >> M;
  int a[M];
  for (int i=0; i<M; i++) cin >> a[i];
  int outputs[M];
  solve(N,M,a, outputs);
  for (int i=0; i<M; i++) {
    cout << outputs[i] << endl;
  }
}

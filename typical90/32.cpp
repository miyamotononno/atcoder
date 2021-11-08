#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

bool calcMinimumTime(const int& N, const int& M, const vector<vector<int>>& A, const set<P>& antiConnect, const set<P>& revAntiConnect, int& minimumTime) {
  const int MAX = 1e9;
  int perm[N]; // i区をperm[i]が走る
  int n=0;
  generate(perm, perm+N, [&n]() { auto t = n; n++; return t; });
  // for_each(perm, perm+N, [](int x) { std::cout << x << ","; });
  minimumTime=MAX;
  bool ok=false;
  do {
    int tmp=0;
    int p;
    for (p=0; p<N; p++) {
      tmp+=A[perm[p]][p];
      if (p==0) continue;
      int x = perm[p-1];
      int y = perm[p];
      bool flag1 = antiConnect.find(P(x,y))!=antiConnect.end();
      bool flag2 = revAntiConnect.find(P(x, y))!=revAntiConnect.end();
      if (flag1 || flag2) {
        tmp = MAX;
        break;
      }
    }
    if (tmp<minimumTime) {
      minimumTime = tmp;
      ok = true;
    }
  } while(next_permutation(perm, perm+N));
  return ok;
}

int main () {
  int N, M;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(N));
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cin >> A[i][j];
    }
  }
  cin >> M;
  set<P> antiConnect, revAntiConnect;
  int x,y;
  for (int i=0; i<M; i++) {
    cin >> x >> y;
    x--; y--;
    antiConnect.insert(P(x,y));
    revAntiConnect.insert(P(y,x));
  }
  int ans;
  if (calcMinimumTime(N,M,A,antiConnect, revAntiConnect, ans)) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
}
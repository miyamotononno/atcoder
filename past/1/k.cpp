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
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int N, Q;
int doubling[22][150003];
vector<int> T[150002];
int dist[150002];
int Qr[100003][2];

void dfs(int idx, int d) {
  dist[idx] =d;
  for (auto p: T[idx]) dfs(p, d+1);
}

int calc_d(int x, int y) {
  y--;
  rep(i, 20) if ((y>>i) & 1) x = doubling[i][x];
  return doubling[0][x];
}

int main() {
  INCANT;
  cin >> N;
  int a, parent;
  rep(i,N) {
    cin >> a;
    a--;
    if (a<0) {
      parent=i;
      doubling[0][i]=i;
      continue;
    }
    doubling[0][i] = a;
    T[a].push_back(i);
  }
  cin >> Q;
  rep(i, Q) {
    cin >> Qr[i][0]>> Qr[i][1];
    Qr[i][0]--;Qr[i][1]--;
  }
  dfs(parent,0);
  rep(j, 20) {
    if (j==0) continue;
    rep(i, N) doubling[j][i] = doubling[j-1][doubling[j-1][i]];
  }
  rep(i, Q) {
    int q1 = Qr[i][0];
    int q2 = Qr[i][1];
    int d = dist[q1]-dist[q2];
    if (d>0 && calc_d(q1, d)==q2) cout << "Yes";
    else cout <<"No";
    cout << endl;
  }
  return 0;
}
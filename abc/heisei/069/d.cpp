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
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int H,W;
int N;
int ans[101][101];
queue<int> que;

void calc() {
  rep(i, H) {
    if (i%2==0) {
      rep(j, W) {
        int q = que.front();que.pop();
        ans[i][j] = q;
      }
    } else {
      for (int j=W-1; j>=0; j--) {
        int q = que.front();que.pop();
        ans[i][j] = q;
      }
    }
  }
}

int main() {
  INCANT;
  cin >> H >> W;
  cin >> N;
  int a;
  rep(i, N) {
    cin >> a;
    while(a--) que.push(i+1);
  }
  calc();
  rep(i, H) {
    rep(j, W) cout << ans[i][j] << ' ';
    cout << endl;
  }
  return 0;
}
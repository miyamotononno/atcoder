#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
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
int H, W, A, B;
bool used[16][16];

ll dfs(int h, int w, int a) { // h, wを探索する段階でAをa枚消費した
  if (h==H) return a==0;
  if (w==W) return dfs(h+1, 0, a); // 右まで達したので次の行にいく
  if (used[h][w]) return dfs(h, w+1, a);
  
  ll res = 0ll;

  // 縦におく
  if (h<H-1 && !used[h+1][w] && 0 < a) {
    used[h][w] = used[h+1][w] = true;
    res += dfs(h, w+1, a-1);
    used[h][w] = used[h+1][w] = false;
  }

  // 横におく
  if (w<W-1 && !used[h][w+1] && 0 < a) {
    used[h][w] = used[h][w+1] = true;
    res += dfs(h, w+1, a-1);
    used[h][w] = used[h][w+1] = false;
  }

  // 何もしない
  res += dfs(h, w+1, a);
  return res;
}

int main() {
  INCANT;
  cin >> H >> W >> A >> B;
  cout << dfs(0, 0, A) << endl;

  return 0;
}
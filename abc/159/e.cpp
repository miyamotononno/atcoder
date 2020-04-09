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
const int INF = 2e9;
int H, W, K;
char S[11][1001];
typedef pair<int, int> P;

int calc(vector<P> kugiri) {
  int ret = 0;
  int left = 0;
  int right = 0;
  vector<int> V(kugiri.size());
  while (right<=W-1) {
    bool end_flag = true;
    rep(j, kugiri.size()) {
      int cnt = 0;
      for(int k=kugiri[j].first; k<=kugiri[j].second; k++) cnt+=S[k][right]-'0';
      V[j]+=cnt;
      if (V[j]>K) {
        if (cnt>K) return INF; // 見込みなし
        else { // 区切って再計算
          ret++;
          left=right;
          end_flag = false;
          rep(i, V.size()) V[i] = 0; 
          break;
        }
      }
    }
    // 縦列は最後まで捜査した
    if (end_flag) right++;
  }
  return ret;
}

int main() {
  INCANT;
  cin >> H >> W >> K;
  rep(i, H) rep(j, W) cin >> S[i][j]; 
  int ans = INF;
  rep(i, pow(2,H-1)) {
    int cnt = 0;
    bitset<9> b(i);
    vector<P> kugiri;
    int top = 0;
    int bottom = 0;
    rep(j, H-1) { // 区切り線
      if (b[j]) {
        cnt++;
        kugiri.push_back(P(top, bottom));
        top = bottom+1;
        bottom = top;
      } else bottom++;
    }
    kugiri.push_back(P(top, H-1));
    ans = min(ans, calc(kugiri)+cnt);
  }
  cout << ans << "\n";
  return 0;
}
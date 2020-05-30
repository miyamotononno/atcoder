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
int N;
typedef pair<int, int> P;
int A[66000], Cnt[66000];

int main() {
  INCANT;
  cin >> N;
  int a;
  rep(i, 1<<N) cin >> A[i];
  vector<P> player;
  rep(i, 1 << N) player.push_back(P(A[i], i));
  int King = -1;
  for (int i=N-1; i>=0; i--) {
    vector<P> tmp(1<<i);
    rep(j, 1<<i) {
      if (player[2*j].first < player[2*j+1].first) {
        tmp[j] = player[2*j+1];
        Cnt[player[2*j].second] = N-i;
      } else {
        tmp[j] = player[2*j];
        Cnt[player[2*j+1].second] = N-i;
      }
    }
    player.clear();
    King = tmp[0].second;
    for (auto p: tmp) player.push_back(p);
  }

  rep(i, 1 << N) {
    if (i==King) cout << N << endl; 
    else cout << Cnt[i] << "\n";
  }
  return 0;
}
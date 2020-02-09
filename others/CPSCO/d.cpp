#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, K;
vector<int> Counts;
// 二分探索

bool is_large(int X) {
  int sum = 0;
  rep(i, Counts.size()){
    sum += Counts[i]/(X+1);
  }
  return sum <= K;
}

ll binary_search(int l, int r) {
  while(r-l>1) {
    ll mid = (r+l)/2;
    if (is_large(mid)) r = mid;
    else l = mid;
  }
  return r; // lがokならここをlに変更すること。
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  int a;
  int tmp =0;
  int cnt = 1;
  rep(i, N) {
    cin >> a;
    if (a!=tmp) {
      tmp = a;
      Counts.push_back(cnt);
      cnt = 1;
    } else {
      cnt++;
    }
  }
  Counts.push_back(cnt);
  int ng = 0;
  int ok = N;
  cout << binary_search(ng, ok) << "\n";
  return 0;
}
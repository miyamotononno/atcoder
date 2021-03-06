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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  vector<int> D(N);
  rep(i, N) cin >> D[i];

  sort(ALL(D));
  int cnt = 1;
  int now = D[0];
  rep(i, N){
    if (now != D[i]){
      cnt++;
      now = D[i];
    }
  }
  cout << cnt << "\n";
  return 0;
}
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
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
struct edge {int x,y; };
int N;
int T[100001];
edge Z[100001];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  T[0] = 0;
  Z[0].x = 0;
  Z[0].y = 0;
  for(int i=1; i<=N; i++){
    cin >> T[i];
    cin >> Z[i].x >> Z[i].y;
  }
  rep(i, N){
    int diff = abs(Z[i+1].x-Z[i].x) + abs(Z[i+1].y-Z[i].y);
    if (abs(T[i+1] - T[i]) < diff) {
      cout << "No" << "\n";
      return 0;
    }
    if ((abs(T[i+1] - T[i]) - diff)%2==1){
      cout << "No" << "\n";
      return 0;
    }
  }
  cout << "Yes" << "\n";
  return 0;
}
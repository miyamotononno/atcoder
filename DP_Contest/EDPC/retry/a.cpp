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
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
using namespace std;
int N;
int H[100003];
int cost[100003];
int INF = 1e9;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N) {
    cin >> H[i];
    cost[i] = INF;
  }

  cost[0] = 0;
  rep(i, N-1) {
    cost[i+1] = min(cost[i]+abs(H[i+1]- H[i]), cost[i+1]);
    cost[i+2] = min(cost[i]+abs(H[i+2]- H[i]), cost[i+2]);
  }

  cout << cost[N-1] << "\n";
  return 0;
}
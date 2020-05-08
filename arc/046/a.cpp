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
priority_queue<int, vector<int>, greater<int> > que;

int main() {
  INCANT;
  cin >> N;
  rep(i, 10) {
    if (i==0) continue;
    int tmp =i;
    rep(j, 9) {
      que.push(tmp);
      tmp*=10;
      tmp+=i;
    }
  }
  rep(i, N-1) {
    que.pop();
  }
  cout << que.top() << "\n";
  return 0;
}
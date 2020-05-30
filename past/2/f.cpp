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
vector<int> A[200004];

int main() {
  INCANT;
  cin >> N;
  int a,b;
  rep(i, N) {
    cin >> a >> b;
    a--;
    A[a].push_back(b);
  }
  priority_queue<int> que;
  int ttl=0;
  rep(i, N) {
    rep(j, A[i].size()) que.push(A[i][j]);
    ttl += que.top(); que.pop();
    cout << ttl << endl;
  }

  return 0;
}
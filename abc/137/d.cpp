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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
const int INF = 1000000007;
int N,M;
vector<int> A[100002];
priority_queue<int>  que;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  int a, b;
  rep(i, N){
    cin >> a >> b;
    if (a > M) continue;
    A[a].push_back(b); //期日の後ろから考えていることに注意
  }
  int ans = 0;
  for (int i=1; i<= M; i++){
    rep(j, A[i].size()){
      que.push(A[i][j]);
    }
    if (!que.empty()){
      ans+= que.top();
      que.pop();
    }
  }

  cout << ans << endl;

  return 0;
}
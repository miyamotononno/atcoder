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
int N, M;
unordered_map<int, int> Mp;
priority_queue<int, vector<int>, greater<int> >  que;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  int a;
  rep(i, N){
    cin >> a;
    Mp[a]++;
  }
  if (M>=Mp.size()){
    cout << 0 << "\n";
    return 0;
  }
  for (auto it=Mp.begin(); it !=Mp.end(); ++it){
    int cnt = it->second;
    que.push(cnt);
  }
  int ans=0;
  rep(i, Mp.size()-M){
    ans+=que.top();
    que.pop();
  }
  cout << ans << "\n";
  return 0;
}
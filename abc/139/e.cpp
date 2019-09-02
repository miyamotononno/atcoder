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
const int INF = 1000000007;
int N;
typedef queue<int> que;
que Mp[1002];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int a;
  rep(i,N){
    rep(j, N-1){
      cin >> a;
      a--;
      Mp[i].push(a);
    }
  }

  int cnt = 0;
  bool flag = true;
  int maxDay=N*(N-1)/2;
  while(flag){
    if (maxDay<0){
      cout << -1 << "\n";
      return 0;
    } 
    rep(i, N){
      if (!Mp[i].empty()){
        flag = false;
        break;
      }
    }
    if (flag) break;
    vector<bool> Today(N, false);
    rep(i, N){
      if (Mp[i].empty()) continue;
      int a = Mp[i].front();
      if (Mp[a].front()==i && !Today[a] && !Today[i]){
        flag = true;
        Mp[i].pop();
        Mp[a].pop();
        Today[i] = true;
        Today[a] = true;
      }
    }
    if (flag) cnt++;
    else {
      cout << -1 << "\n";
      return 0;
    }
  }

  
  cout << cnt << "\n";
  return 0;
}

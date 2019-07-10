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
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
int N, K;
int v[53];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  rep(i, N) cin >> v[i];

  int max_value = 0;
  rep(cnt, min(N, K)+1){
    int ta = K-cnt; //throw awayの回数
    rep(a,cnt+1){
      priority_queue<int, vector<int>, greater<int> > pque;
      int b = cnt - a;
      int value = 0;
      rep(i, a){
        pque.push(v[i]);
        value+=v[i];
      }
      rep(i, b){
        pque.push(v[N-i-1]);
        value+=v[N-i-1];
      }
      rep(i, ta){
        if (pque.empty()) break;
        int top = pque.top();
        if(top>0) break;
        value-=top;
        pque.pop();
      }
      max_value=max(max_value, value);
    }
  }
  
  cout << max_value << endl;
  return 0;
}

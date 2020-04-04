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
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
queue<int> que;

ll calc() {
  int cnt = 9;
  rep(i,9) que.push(i+1);
  while(cnt<N) {
    ll q = que.front(); que.pop();
    // 0, 1-8, 9
    if (q%10==0) {
      rep(i,2) {
        que.push(q*10+i);
        cnt++;
        if (cnt==N) return q*10+i;
      }
    } else if (q%10==9) {
      rep(i,2) {
        que.push(q*10+8+i);
        cnt++;
        if (cnt==N) return q*10+8+i;
      }
    } else {
      rep(i, 3) {
        que.push(q*10+q%10-1+i);
        cnt++;
        if (cnt==N) return q*10+q%10-1+i;
      }
    }

  }
  return cnt;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  if (N<10) {
    cout << N << "\n";
    return 0;
  }
  cout << calc() << "\n";
  return 0;
}
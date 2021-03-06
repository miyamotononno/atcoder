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
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
int V[100001];
priority_queue<double, vector<double>, greater<double> >  que;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  double a;
  rep(i, N){
    cin >> a;
    que.push(a);
  };
  while(que.size()>1){
    double f = que.top();
    que.pop();
    double s = que.top();
    que.pop();
    double nxt = (f+s)/2.0;
    que.push(nxt);
  }
  cout << que.top() << endl;
  return 0;
}
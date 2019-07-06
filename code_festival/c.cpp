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
typedef std::pair<ll, ll> pi;
using namespace std;
const ll MOD = 1000000007LL;
int N, K;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    priority_queue<pi, vector<pi>, greater<pi> > pque;

    rep(i, N){
      ll a, b;
      cin >> a >> b;
      pque.push(make_pair(a, b));
    }
    ll time=0;
    rep(i, K){
      pi t = pque.top();
      ll f = t.first;
      time += f;
      pque.pop();
      pque.push(make_pair(f+t.second,t.second));
    }

    cout << time << endl;

    return 0;
}
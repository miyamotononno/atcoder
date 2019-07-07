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
#define rep_down(i,n) for (int i=n-1; i>=0; --i)
typedef long long ll;
using namespace std;
int N;
const ll MOD = 1000000007LL;
ll ls, rs;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    priority_queue<ll, vector<ll>, greater<ll> > left_pque;
    priority_queue<ll> right_pque;


    cin >> N;

    ll a[3*N];
    ll left_sum[N+1];
    ll right_sum[N+1];

    rep(i, N){
      ll b;
      cin >> b;
      a[i] = b;
      ls+=b;
      left_pque.push(b);
    } 
    rep(i, N) cin >> a[N+i]; 
    rep(i, N){
      ll b;
      cin >> b;
      a[2*N+i] = b;
      rs+=b;
      right_pque.push(b);
    }

    left_sum[0] = ls;
    rep(i, N){
      int trgt =a[N+i];
      ls+= trgt;
      left_pque.push(trgt);
      ll c = left_pque.top();
      ls -= c;
      left_pque.pop();
      left_sum[i+1] = ls;
    }

    right_sum[N] = rs;
    rep_down(i, N){ // N-1から0へ。
      int trgt =a[N+i];
      rs+=trgt;
      right_pque.push(trgt);
      ll c = right_pque.top();
      rs -= c;
      right_pque.pop();
      right_sum[i] = rs;
    }

    ll ans = (-1)* N * MOD;
    rep(i, N+1) ans = max(ans, left_sum[i] - right_sum[i]);
    cout << ans << endl;
    return 0;
}
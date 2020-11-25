#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <deque>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n;
ll A[100005];
ll B[100005][2];

ll calc(deque<ll> que, bool rev) { // 中心が最小か、最大か
  memset(B, 0, sizeof(B));
  ll mid;
  if (rev) {
    mid = que.back();
    que.pop_back();
  } else {
    mid = que.front();
    que.pop_front();
  }
  vector<int> L, R;
  L.push_back(mid);R.push_back(mid);
  int idx = 1;
  rev = rev==false;
  while(!que.empty()) {
    ll left, right;
    if (rev) {
      left = que.back();
      que.pop_back();
    } else {
      left = que.front();
      que.pop_front();
    }
    L.push_back(left);
    if (que.empty()) break;
    if (rev) {
      right = que.back();
      que.pop_back();
    } else {
      right = que.front();
      que.pop_front();
    }
    R.push_back(right);
    rev = rev==false;
    idx++;
  }
  ll ret = 0ll;
  rep(i, L.size()-1) {
    ret+=abs(L[i+1]-L[i]);
  }
  rep(i, R.size()-1) {
    ret+=abs(R[i+1]-R[i]);
  }
  return ret;
}

int main() {
  INCANT;
  cin >> n;
  rep(i, n) cin >> A[i];
  if (n==2) {
    cout << A[1] - A[0] << endl;
    return 0;
  }
  sort(A,A+n);
  deque<ll> que;
  rep(i, n) que.push_back(A[i]);
  
  
  cout << max(calc(que, true), calc(que, false)) << "\n";
  return 0;
}
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
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
ll A[100005], B[100005];
priority_queue<ll> pque;

int main() {
  INCANT;
  cin >> n;
  ll sum = 0ll;
  rep(i, n) {
    cin >> A[i];
    sum+=A[i];
  }
  ll rest = sum;
  rep(i, n) {
    cin >> B[i];
    rest-=B[i];
  }
  if (rest<0) {
    cout << -1 << "\n";
    return 0;
  }
  vector<ll> wantWizard;
  rep(i, n) {
    if (A[i]-B[i]<0) wantWizard.push_back(B[i]-A[i]);
    else if (A[i]-B[i]>0) pque.push(A[i]-B[i]);
  }
  int ans = wantWizard.size();
  int idx = 0;
  while(!pque.empty()) {
    ll d = pque.top(); pque.pop();
    if (idx==wantWizard.size()) break;
    ans++;
    while(d>0 && idx<wantWizard.size()) {
      if (wantWizard[idx]>d) {
        wantWizard[idx]-=d;
        break;
      } else {
        d-=wantWizard[idx];
        idx++;
      }
    }
  }

  cout << ans << endl;
  
  
  return 0;
}
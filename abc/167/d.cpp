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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, A[200004];
ll K;
ll init[200004];

int main() {
  INCANT;
  cin >> N >> K;
  int a;
  rep(i, N) {
    cin >> a;
    a--;
    A[i]=a;
  }
  fill(init, init+N, -1);
  init[0]=0;
  int next=0;
  ll cnt=0;
  while(cnt < K) {
    cnt++;
    next = A[next];
    if (init[next]>=0) break;
    init[next]=cnt;
  }
  if (cnt==K) {
    cout << next+1 << endl;
    return 0;
  }
  ll circle=cnt-init[next];
  ll amari = (K-cnt)%circle;
  rep(i, N) {
    if (init[i]==amari+init[next]) {
      cout << i+1 << "\n";
      break;
    }
  }
  
  return 0;
}
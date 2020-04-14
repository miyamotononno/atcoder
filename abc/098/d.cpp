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
int N, A[200005];

ll calc() {
  int left=0;
  int right=0;
  int B=0;
  ll cnt=0;
  while(left<N && right<N) {
    assert(left<=right);
    bool ok=true;
    rep(i, 20) {
      int mask = 1<<i;
      int a = A[right]&mask;
      int b = B&mask;
      if (a&b) {
        ok = false;
        break;
      }
    }
    if (right<N-1 && ok) {
      B = B^A[right];
      right++;
    } else {
      cnt+=right-left;
      if (ok) cnt++;
      left++;
      if (right==left) B=0;
      else {
        if (left==N) break;
        rep(i, 20) {
          int mask = 1<<i;
          if (A[left-1]&mask) {
            assert(B&mask);
            B-=mask;
          }
        }
      }
    }
  }
  return cnt;
}

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> A[i];
  cout << calc() << "\n";
  return 0;
}

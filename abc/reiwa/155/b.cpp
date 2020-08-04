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
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
int A[103];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N) cin >> A[i];

  string ans = "DENIED";
  rep(i, N) {
    if (A[i]%2==0) {
      if (A[i]%3!=0 && A[i]%5!=0) {
        cout << ans << "\n";
        return 0;
      }
    }
  }
  cout << "APPROVED" << "\n";
  return 0;
}
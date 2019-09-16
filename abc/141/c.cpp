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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N, Q, A[100003], K;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K >> Q;
  int a;
  rep(i, Q){
    cin >> a;
    a--;
    A[a]+=1;
  }

  rep(i, N){
    if (K-(Q-A[i])<=0) cout << "No" << "\n";
    else cout << "Yes" << "\n";
  }

  return 0;
}
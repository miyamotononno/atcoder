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
ll N, M;
int A[100001];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  if (N==1){
    if (M==1) cout << 1 << "\n";    
    else cout << M-2 << "\n";
    return 0;
  }
  if (M==1){
    if (N==1) cout << 1 << "\n";    
    else cout << N-2 << "\n";
    return 0;
  }
  if (M==2 || N==2){
    cout << 0 << "\n";
    return 0; 
  }
  cout << (N-2)*(M-2) << "\n";
  return 0;
}
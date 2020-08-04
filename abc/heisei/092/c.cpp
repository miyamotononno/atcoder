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
int N;
ll A[100001];
ll B[100001];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N) cin >> A[i];
  ll sm = abs(A[0]);
  rep(i, N-1){
    sm += abs(A[i+1] - A[i]);
  }
  sm += abs(A[N-1]);

  rep(i, N){
    if (i==0) {
      if (A[0] > 0 && A[1] < A[0]) B[0] = A[0] - max(A[1], 0ll);
      else if (A[0] < 0 && A[1] > A[0]) B[0] = abs(A[0] - min(A[1], 0ll));
      else B[0] = 0;
      continue;
    }
    if (i==N) {
      if (A[N-1] > 0 && A[N-2] < A[0]) B[0] = A[N-1] - max(A[N-2], 0ll);
      else if (A[N-1] < 0 && A[N-2] > A[0]) B[0] = abs(A[N-1] - min(A[N-2], 0ll)); 
      else B[0] = 0;
      continue;
    }
    
    if (A[i] > A[i-1] && A[i] > A[i+1]) B[i] = abs(A[i] - max(A[i-1],A[i+1]));
    else if (A[i] < A[i-1] && A[i] < A[i+1]) B[i] = abs(A[i] - min(A[i-1],A[i+1]));
    else B[i] = 0;
  }

  rep(i, N){
    cout << sm - 2 * B[i] << endl;
  }
  
  return 0;
}
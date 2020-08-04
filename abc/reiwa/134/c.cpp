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
int A[200005], L[200005], R[200005];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N){
    cin >> A[i];
  }

  rep(i, N){
    if (i==0) continue;
    if (i==1){
      L[i] = A[0];
      continue;
    }
    L[i] = max(L[i-1], A[i-1]);
  }

  rep_down(i, N){
    if (i==N-1) continue;
    if (i==N-2){
      R[i] = A[N-1];
      continue;
    }
    R[i] = max(R[i+1], A[i+1]);
  }

  rep(i, N){
    if (i==0){
      cout << R[0] << endl;
      continue;
    }
    if (i==N-1){
      cout << L[N-1] << endl;
      continue;
    }
    int a = max(L[i], R[i]);
    cout << a << endl;
  }
  return 0;
}
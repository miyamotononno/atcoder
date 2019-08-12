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
typedef long long ll;
using namespace std;
int N, K;
int A[100003];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  int f = 0;
  rep(i, N) cin >> A[i];
  rep(i, N){
    if (A[i] == K) {
      f = 1;
      break;
    };
    if (A[i] > K) {
      f = 2;
      continue;
    }
  }
  if (f==0){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  if (f==1){
    cout << "POSSIBLE" << endl;
    return 0;
  }

  vector<int> B;
  rep(i, N-1){
    if (A[i+1] == A[i]) continue;
    B.push_back(abs(A[i+1] - A[i]));
  }
  
  int g = B[0];
  rep(i, B.size()){
    if (g == 1) break;
    g = gcd(g, B[i]);
  }
  if (g==K){
    cout << "POSSIBLE" << endl;
    return 0;
  }
  
  bool flag = false;
  rep(i, N){
    if(abs(A[i]-K)%g==0){
      flag = true;
      break;
    }
  }
  string ans = flag?"POSSIBLE":"IMPOSSIBLE";
  cout << ans << endl;
  return 0;
}
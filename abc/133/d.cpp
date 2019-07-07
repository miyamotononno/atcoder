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
int N;
int A[100003];
int M[100003];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  ll sm=0;
  ll sm2=0;
  int a;
  rep(i, N){
    cin >> a;
    A[i] = a;
    sm += a; 
    if (i%2==0) sm2 +=a;
  }

  M[0] = 2*sm2 - sm;
  
  for(int i=1; i<N; ++i){
    ll c = A[i-1] - M[i-1]/2;
    M[i] = c*2; 
  }

  rep(i, N){
    if (i==N-1){
      cout << M[i] << endl;
      break;
    }
    cout << M[i] << " ";
  } 
  return 0;
}
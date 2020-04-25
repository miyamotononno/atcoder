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
int A[90005][2], D, H, W, Q;
int L[100005], R[100005];
int M[90005], SUM[90005];

void init() {
  // D前との魔力の差分
  for (int i=D; i<H*W; i++) {
    M[i] = abs(A[i][0]-A[i-D][0])+abs(A[i][1]-A[i-D][1]);
  }
  for (int i=D; i<H*W; i++) {
    SUM[i]=SUM[i-D]+M[i];   
  }
}

int main() {
  INCANT;
  cin >> H >> W >> D;
  int a;
  rep(i, H) {
    rep(j, W) {
      cin >> a;
      a--;
      A[a][0]=i;
      A[a][1]=j;
    }
  }
  init();
  cin >> Q;
  rep(i, Q) cin >> L[i] >> R[i];
  rep(i, Q) {
    int l =L[i],r=R[i];
    l--;r--;
    cout << SUM[r]-SUM[l] << endl; 
  }
  
  return 0;
}
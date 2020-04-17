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
int N;
string S;
char c[4] = {'A', 'B', 'X', 'Y'};
int d1[2], d2[2];

int calc2(int l1, int l2, int r1, int r2) {
  int idx=0;
  int cnt=0;
  while(idx < N) {
    cnt++;
    if (idx==N-1) {
      idx++;
      break;
    }
    if (S[idx]== c[l1] && S[idx+1] ==c[l2]) idx+=2;
    else if (S[idx]==c[r1] && S[idx+1] ==c[r2]) idx+=2;
    else idx++;
  }
  return cnt;
}

int calc() {
  int ret =INF;
  rep(i, 4) { // L1
    rep(j, 4) {// L2
      rep(k, 4) { // R1
        rep(l,4) { // R2
          if (i==k && l==k) continue;
          ret =min(ret, calc2(i,j,k,l)); 
        }
      }
    }
  }
  return ret;
}

int main() {
  INCANT;
  cin >> N >> S;
  cout << calc() << "\n";
  return 0;
}
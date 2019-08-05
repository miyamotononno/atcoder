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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
int A, B, C;

int first_cnt(int mx){
  int cnt = 0;
  while (mx >= A+2){
    A += 2;
    cnt++;
  }
  while (mx >= B+2){
    B += 2;
    cnt++;
  }
  while (mx >= C+2){
    C += 2;
    cnt++;
  }
  return cnt;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B >> C;
  
  int mx = max(max(A, B), C);
  int ans = first_cnt(mx);
  int diff = mx - A + mx- B + mx - C;
  if (diff%2){
    ans += 2*diff;
  } else {
    ans += diff/2;
  }
  cout << ans << endl;
  return 0;
}
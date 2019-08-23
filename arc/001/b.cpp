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
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int A, B;

int checkCnt(int diff){
  if (diff==0) return 0;
  if (diff==1 || diff ==5) return 1;
  if (diff==9 || diff==2 || diff==4 || diff==6){
    return 2;
  }
  return 3;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B;
  if (B==A){
    cout << 0 << "\n";
    return 0;
  }
  if (B<A) B+=2*(A-B);
  int cnt=0;
  while(B-A>=10){
    A+=10;
    cnt++;
  }
  cnt+=checkCnt(B-A);
  cout << cnt << "\n";

  return 0;
}
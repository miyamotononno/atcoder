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
string S;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  int trgt = 0;
  int cnt = 0;
  char pre[2] = "";
  while (trgt < S.size()){
    char now[2] = "";
    now[0] = S[trgt];
    if (strcmp(now, pre) != 0){
      pre[0] = now[0];
      pre[1] = now[1];
      cnt += 1;
      trgt += 1;
      continue;
    }
    trgt += 1;
    now[1] = S[trgt];
    if (strcmp(now, pre) != 0){
      pre[0] = now[0];
      pre[1] = now[1];
      cnt += 1;
      trgt += 1;
    }
  }

  cout << cnt << endl;

  return 0;
}
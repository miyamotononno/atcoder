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
string S;
int T[100003];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  int i =0;
  int even_cnt = 0;
  int odd_cnt = 0;
  int l_tamari = 0;
  int r_tamari = 1;
  while(i < S.size()){
    if (i%2) even_cnt+= 1;
    else odd_cnt+= 1;
    char p = S[i];
    char n = S[i+1];
    if (p == 'L' && n == 'R'){
      if (l_tamari%2 == 0){
        T[l_tamari] = odd_cnt;
        T[r_tamari] = even_cnt;
        even_cnt = 0;
        odd_cnt = 0;
      } else {
        T[l_tamari] = even_cnt;
        T[r_tamari] = odd_cnt;
        even_cnt = 0;
        odd_cnt = 0;
      }
      i++;
      continue;
    }
    if (p == 'R' && n == 'L'){
      l_tamari = i;
      r_tamari = i+1;
    }
    i++;
  }

  // 最後
    if (l_tamari%2 == 0){
      T[l_tamari] = odd_cnt;
      T[r_tamari] = even_cnt;
    } else {
      T[l_tamari] = even_cnt;
      T[r_tamari] = odd_cnt;
    }

  rep(i, S.size()){
    cout << T[i] << ' ';
  }
  return 0;
}
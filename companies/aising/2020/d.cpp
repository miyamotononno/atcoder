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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
int N;
string s;
int MODplus1[200005];
int MODminus1[200005];

int f(int x) {
  if (x==0) return 0;
  int cnt=0;
  rep(i, 20) {
    if ((1<<i)&x) cnt++;
  }
  return f(x%cnt)+1;
} 

int calc_mod(int x, int _mod[200005]) {
  if (x==0) return 0;
  _mod[0] = 1;
  rep(i, N) {
    if (i==0) continue;
    _mod[i] = 2*_mod[i-1]%x;
  }
  int sum = 0;
  rep(i, N) {
    if (s[i]=='1') sum+=_mod[N-1-i];
    sum%=x;
  }
  return sum;
}

int main() {
  INCANT;
  cin >> N >> s;
  int cnt=0;
  rep(i, N) if (s[i]=='1') cnt++;
  int sum1 = calc_mod(cnt+1, MODplus1);
  int sum2 = calc_mod(cnt-1, MODminus1);
  rep(i, N) {
    int sum;
    if (s[i]=='1') { // 1→0
      if (cnt-1==0) {
        cout << 0 << endl;
        continue;
      }
      sum=sum2;
      sum-=MODminus1[N-1-i];
      sum+=(cnt-1);
      sum%=(cnt-1);
    } else { // 0→1
      sum=sum1;
      sum+=MODplus1[N-1-i];
      sum%=(cnt+1);
    }
    cout << f(sum) + 1 << endl;
  }  
  return 0;
}

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
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
int PF[102][102]; // 0始まりに注意
int Target[102];

map< int, int > prime_factor(int n) {
  map< int, int > ret;
  for(int i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int calc(int num){
  int cnt = 0;
  rep(i, N){
    if (Target[i]>=num-1) cnt++;
  }
  return cnt;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N){
    for(auto p : prime_factor(i+1)) {
      while(p.second--){
        PF[i][p.first-1]++;
      }
    }
    rep(j, i+2){
      PF[i+1][j]=PF[i][j];
    }
  }

  rep(i, N) Target[i] = PF[N-1][i];
  int c_3 = calc(3);
  int c_5 = calc(5);
  cout << calc(75)+calc(25)*(c_3-1)+calc(15)*(c_5-1)+c_5*(c_5-1)*(c_3-2)/2 << "\n"; //最後に2で割っているのは2C1に依る
  return 0;
}
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
int N;
int A[200004];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N)  cin >> A[i];
  int sm = 0;
  int cnt = 0;  
  while(cnt < N){
    cnt++;
    int p_sum = 0;
    while (A[cnt+1] > A[cnt]){
      p_sum++;
      cnt ++;
    }
    sm+=p_sum;
  }
  
  cout << N - sm << endl;
  return 0;
}
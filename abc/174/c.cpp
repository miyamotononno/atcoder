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
int N;
int MOD[1000003];

map<int, int> prime_factor(int n) {
  map<int, int> ret;
  for(int i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main() {
  INCANT;
  cin >> N;
  if (N%2==0 || N%5==0) {
    cout << -1 << endl;
    return 0;
  }
  if (N==7 || N==1) {
    cout << 1 << endl;
    return 0;
  }
  MOD[0] = 7%N;
  rep(i, N) {
    if (i==0) continue;
    int tmp = (MOD[i-1]*10+7)%N;
    if (tmp==0) {
      cout << i+1 << endl;
      return 0;
    }
    MOD[i] = tmp;
  }
  cout << -1 << endl;
  return 0;
}
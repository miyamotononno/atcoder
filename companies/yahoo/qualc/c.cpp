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
typedef long long ll;
using namespace std;
ll k,a,b;

int main() {
  INCANT;
  cin >> k >> a >> b;
  if (a>=b-2) {
    cout << k + 1 << endl;
    return 0;
  }
  // a枚まで増やす
  k-=a-1;
  if (k<0) {
    cout << k + 1 << endl;
    return 0;
  }
  ll ret = (b-a)*(k/2) + a; 
  cout << ret+k%2 << "\n";
  return 0;
}
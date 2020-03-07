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
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int A, B;

int calc1() {
  int a = min(B*10, A*25/2);
  int b = max(B*10, A*25/2);
  while (a<=b+1) {
    int c = a*2/25;
    int d = a*0.1;
    if (c == A && d==B) {
      return a;
    }
    a++;
  }
  return -1;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B;
  cout << calc1() << "\n";
  return 0;
}
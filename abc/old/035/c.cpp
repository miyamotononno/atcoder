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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, Q;
int k[200005];

int main() {
  INCANT;
  cin >> N >> Q;
  int a,b;
  rep(i, Q) {
    cin >> a >> b;
    a--;b--;
    k[a]++; k[b+1]--;
  }
  rep(i, N) k[i+1]+=k[i];
  rep(i, N) {
    cout << k[i]%2;
  }
  cout << endl;
  return 0;
}
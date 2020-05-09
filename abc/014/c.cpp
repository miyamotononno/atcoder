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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
int Q[1000002];

int main() {
  INCANT;
  cin >> N;
  int a,b;
  rep(i, N) {
    cin >> a >> b;
    Q[a]++;
    Q[b+1]--;
  }
  int MAX=1;
  rep(i, 1000000) Q[i+1] += Q[i]; 
  rep(i, 1000001) MAX=max(MAX, Q[i]);
  cout << MAX << endl;
  return 0;
}

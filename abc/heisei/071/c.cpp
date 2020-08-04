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
int N;
map<ll, int> M;

int main() {
  INCANT;
  cin >> N;
  ll a;
  rep(i, N) {
    cin >> a;
    M[a]++;
  }
  ll b=0ll,c=0ll;

  for (auto p : M) {
    if (p.second>=2) { 
      b=c;
      c=p.first;
    }
    if (p.second>=4) b = p.first;
  } 
  cout << b*c << "\n";
  return 0;
}
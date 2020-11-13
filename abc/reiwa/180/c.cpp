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
ll N;




int main() {
  INCANT;
  cin >> N;
  vector<ll> ans;
  for(ll i=1; i*i<=N; i++) {
    if (N%i==0) {
      ans.push_back(i);
      if (i!=N/i) ans.push_back(N/i);
    }
  }
  sort(ALL(ans));
  for (auto a: ans) cout << a << "\n";
  return 0;
}
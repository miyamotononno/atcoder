#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
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
int T;

int main() {
  INCANT;
  cin >> T;
  vector<ll> A(T);
  ll n;
  rep(i, T) {
    cin >> n;
    A[i]=n;
  }
  rep(i, T) {
    if (A[i]%2==1) {
      cout << "Odd" << endl;
      continue;
    }
    ll d = A[i]/2; 
    if (d%2==1) {
      cout << "Same" << endl;
      continue;
    }
    cout << "Even" << endl;
  } 
  
  return 0;
}
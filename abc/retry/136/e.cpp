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
int n, k;
int A[504];


vector<int> prime_factor(int s) {
  vector<int> ret;
  for (int i=1; i*i<=s; i++) {
    if (s%i==0) {
      if (i*i==s) ret.push_back(i);
      else {
        ret.push_back(i);
        ret.push_back(s/i);
      }
    }
  }
  sort(ALL(ret), greater<int>());
  return ret;
}

bool calc(vector<int> Amari, int& p) {
  int sz = Amari.size();
  int Sum[sz+1], RevSum[sz+1];
  Sum[0] = 0;
  rep(i, sz) Sum[i+1] = Sum[i]+Amari[i];
  RevSum[sz] = 0;
  for (int i=sz-1; i>=0; i--) RevSum[i]=RevSum[i+1]+ (p-Amari[i]);
  rep(i, sz+1) {
    if (Sum[i]==RevSum[i]) {
      if (Sum[i]<=k) return true;
    }
  }
  return false;
}

int main() {
  INCANT;
  cin >> n >> k;
  rep(i, n) cin >> A[i];
  int sum = 0;
  rep(i, n) sum+=A[i];

  vector<int> pf = prime_factor(sum);
  for (auto p: pf) {
    vector<int> Amari;
    rep(i, n) {
      if (A[i]%p) Amari.push_back(A[i]%p);
    }
    if (Amari.size()==0) {
      cout << p << endl;
      return 0;
    }
    sort(ALL(Amari));
    if (calc(Amari, p)) {
      cout << p << endl;
      return 0;
    }
  }
  cout << 1 << "\n";
  return 0;
}
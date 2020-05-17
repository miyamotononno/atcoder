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
ll X[100004];
ll A, B;

int main() {
  INCANT;
  cin >> N >> A >> B;
  rep(i, N) cin >> X[i];
  ll SUM=0ll;
  rep(i, N-1) {
    if ((X[i+1]-X[i])*A<B) SUM+=(X[i+1]-X[i])*A;
    else SUM+=B;
  }
  cout << SUM << "\n";
  return 0;
}
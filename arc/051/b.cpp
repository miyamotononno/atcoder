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
ll K;
ll counter=0;

void gcd(ll a, ll b) {
  if (a==0) return;
  counter++;
  gcd(b%a,a);
}

int main() {
  INCANT;
  cin >> K;
  ll a = 1;
  ll b = 1;
  counter=1;
  while(counter<K) {
    ll tmp=b;
    b+=a;
    a=tmp;
    counter++;
  }
  cout << a << ' ' << b << "\n";
  return 0;
}
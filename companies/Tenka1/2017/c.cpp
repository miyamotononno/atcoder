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
  for (ll h=1; h<=3500; h++) {
    for (ll n=h; n<=3500; n++) {
      ll Nhn = N*h*n;
      ll bunbo = 4*h*n-N*n-N*h;
      if (bunbo==0) continue;
      if (Nhn%bunbo==0) {
        ll w = Nhn/bunbo;
        if (w>=0) {
          cout << h << ' ';
          cout << n << ' ';
          cout << w << endl;
          return 0;
        }
      }
    } 
  } 
  return 0;
}
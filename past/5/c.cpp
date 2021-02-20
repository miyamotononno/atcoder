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
int n;
const string D = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  INCANT;
  cin >> n;
  if (n==0) {
    cout << 0 << endl;
    return 0;
  }
  vector<char> E;
  while(n>0) {
    E.push_back(D[n%36]);
    n/=36;
  }
  for (int i=E.size()-1; i>=0; i--) {
    cout << E[i];
  }
  cout << endl;
  return 0;
}
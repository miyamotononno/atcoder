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
string s;
unordered_map<char, bool> U;

int main() {
  INCANT;
  cin >> n;
  cin >> s;
  vector<char> D;
  for (int i=n-1; i>=0; i--) {
    if (!U[s[i]]) D.push_back(s[i]);
    U[s[i]] = true;
  }

  for (int i=D.size()-1; i>=0; i--) {
    cout << D[i];
  }
  cout << endl;
  return 0;
}
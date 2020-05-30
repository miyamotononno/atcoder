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
string S, T;

int trans(string s) {
  if (s[0]=='B') {
    int c = s[1]-'0';
    return -(c-1);
  }
  return s[0]-'0';
}
 
int main() {
  INCANT;
  cin >> S >> T;
  
  int s = trans(S);
  int t = trans(T); 
  cout << abs(s-t) << "\n";
  return 0;
}
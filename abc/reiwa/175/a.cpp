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
string S;

int main() {
  INCANT;
  cin >> S;
  if (S[0]==S[1] && S[1]==S[2] && S[0]=='R') {
    cout << 3 << endl;
  } else if ((S[0]==S[1] && S[1]=='R' )|| (S[1]==S[2]&& S[1]=='R' )) {
    cout << 2 << "\n";
  } else if (S[0]=='R' || S[1]=='R' || S[2]=='R'){
    cout << 1 << "\n";
  } else cout << 0 << "\n";
  
  return 0;
}
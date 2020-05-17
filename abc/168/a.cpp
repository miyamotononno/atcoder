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

int main() {
  INCANT;
  cin >> N;
  N%=10;
  if (N==2 || N==4 || N==5 || N==7|| N==9) cout << "hon";
  else if (N==0 || N==1 || N==6 || N==8) cout << "pon";
  else cout << "bon";
  cout <<  "\n";
  return 0;
}
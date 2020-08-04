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
string s;
bool mmyy, yymm;

int main() {
  INCANT;
  cin >> s;
  int a = (s[0]-'0')*10+s[1]-'0';
  if (a>0 && a<13) mmyy=true;
  a = (s[2]-'0')*10+s[3]-'0';
  if (a>0 && a<13) yymm=true;
  if  (mmyy && yymm) cout <<  "AMBIGUOUS";
  else if (mmyy) cout << "MMYY";
  else if (yymm) cout << "YYMM";
  else cout << "NA";
  cout << "\n";
  return 0;
}
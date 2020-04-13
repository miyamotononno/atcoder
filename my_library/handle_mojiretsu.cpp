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
int A[100000];
void handle_string(string S) {
  string T = "abc";
  char c = 'd';
  cout << S+T << "\n";
  cout << S+c << "\n";
  cout << S.substr(1) << "\n";
  cout << S.substr(4, 100) << "\n"; // 超えても問題ない
}

ll stringToLong(string s){
  ll res = 0;
  rep(i, s.size()){
    int a = s[i] - '0';
    res = res*10+a;
  }
  return res;
}

int charToInt(char c) { // "A-Z,a-z"の想定
  return c -'0';
}
// A:65, Z:90, a:97, z:122

char intToChar(int num) {
  return num+'0';
}

int main() {
  INCANT;
  char c1 = 'Z';
  int n = charToInt(c1);
  char c2 = intToChar(n);
  assert(c1==c2); // ok
  c1 = 'R';
  c2 = 'G';
  char c3 = 'B';
  int sm = charToInt(c1)+charToInt(c2)+charToInt(c3);
  if (charToInt(c1) + charToInt(c2) == sm-charToInt(c3)) {
    assert(c3==intToChar(charToInt(c3))); //ok
  }
  return 0;
}

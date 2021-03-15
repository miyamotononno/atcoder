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
#include <stack>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
string S;
ll X;

bool isNumber(char c) {
  return (c-'0')>=1 && (c-'0')<=9;
}

int main() {
  INCANT;
  cin >> S >> X;
  ll sz;
  while(true) {
    sz=0ll;
    for (char c: S) {
      if (!isNumber(c)) {
        if (sz==X-1) {
          cout << c << endl;
          return 0;
        }
        sz++;
      } else {
        ll d = c - '0';
        if (sz*(d+1)<X) {
          sz*=(d+1);
        } else {
          X%=sz;
          if (X==0) X = sz;
          break;
        }
      }
    }
  }
  
  return 0;
}
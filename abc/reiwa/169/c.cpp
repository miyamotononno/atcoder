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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
ll A;
string B;

int main() {
  INCANT;
  cin >> A >> B;
  ll b1 = B[0]-'0';
  ll b2 = B[2]-'0';
  ll b3 = B[3]-'0';

  cout << (A*b1*100+A*b2*10+A*b3)/100 << "\n";
  return 0;
}
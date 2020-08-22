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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;
int h1,m1,h2,m2,k;

int main() {
  INCANT;
  cin >> h1>>m1>>h2>>m2>>k;
  int tm = 0;
  tm+=m2-m1;
  tm+=(h2-h1)*60;
  cout << tm -k << endl;
  return 0;
}
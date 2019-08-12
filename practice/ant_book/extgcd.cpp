#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>

// 拡張ユークリッドの互除法
// ax + by = gcd(a,b)の整数解(x, y)は常に存在する

// 返り値はgcd(a, b)とする
int extgcd(int a, int b, int& x, int& y){
  int d = a;
  if (b != 0){
    d = extgcd(b, a % b,  y, x);
    y -= (a/b)*x;
  } else {
    x =1; y = 0;
  }
  return d;
}
  
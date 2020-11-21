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
#include <deque>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int n;
string s;

int main() {
  INCANT;
  cin >> n >> s;
  deque<char> que;
  for(auto c: s) {
    switch(c) {
      case 'f':
      case 'o':
      case 'x':
        que.push_back(c);
        break;
      default:
        que.push_back('-');
        break;
    }
  }
  
  int ret = s.size();
  deque<char> garbage;
  while(!que.empty()) {
    char t = que.front(); que.pop_front();
    if (t=='-') garbage.push_back(t);
    else if (t=='f' || t=='o') garbage.push_back(t);
    else {
      if (garbage.empty()) {
        garbage.push_back(t); // x
        continue;
      }
      if (!garbage.empty()) {
        char g = garbage.back(); garbage.pop_back();
        if (g!='o') {
          garbage.push_back(g);
          garbage.push_back(t);
          continue;
        }
        if (garbage.empty()) {
          garbage.push_back(g);
          garbage.push_back(t);
          continue;
        }
        // 今ox
        char preg = g;
        g = garbage.back(); // f  or ?
        if (g!='f') {
          garbage.push_back(preg);
          garbage.push_back(t);
          continue;
        }
        garbage.pop_back(); // f
        ret-=3;
      }
    }
  }

  cout << ret << endl;
  return 0;
}
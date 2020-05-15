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
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
string s;

// アンバランスならばいずれか3文字のうち2文字はunbalance

int main() {
  INCANT;
  cin >> s;
  int n = s.size();
  if (n==2) {
    if (s[0]==s[1]) {
      cout << 1 << ' ';
      cout << 2 << endl;
      return 0;
    }
    cout << -1 << ' ';
    cout << -1 << endl;
    return  0;  
  }

  for (int i=2; i<n; i++) {
    if (s[i-2]==s[i] || s[i-1]==s[i] || s[i-2]==s[i-1]) {
      cout << i-1 << ' ';
      cout << i+1 << endl;
      return 0;
    }
  }

  cout << -1 << ' ';
  cout << -1 << endl;
  return 0;
}
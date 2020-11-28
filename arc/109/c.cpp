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
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int n,k;
string s;


int getWinner(char a, char b) {
  if (a==b) return a;
  else {
    if (b-a>0) swap(a,b);
    if (a=='R' && b=='P') {
      return 'P';
    } else if (a=='S' && b=='R') {
      return 'R';
    } else if (a=='S' && b=='P'){
      return 'S';
    }
  }
}

int main() {
  INCANT;
  cin >> n >> k;
  cin >> s;
  if (n==1) {
    cout << s[0] << endl;
    return 0;
  }

  rep(step, k) {
    string t = s+s;
    rep(i, n) s[i] = getWinner(t[2*i], t[2*i+1]);
  }
  cout << s[0] << endl;
  return 0;
}
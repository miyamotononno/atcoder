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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n;

bool check(int n, int& row, int& col) {
  int i=1;
  while(i*(i+1)/2<=n) {
    if (n==i*(i+1)/2) {
      row = i+1;
      col = i;
      return true;
    }
    i++;
  }
  return false;
}
int main() {
  INCANT;
  cin >> n;
  int row, col;
  if (!check(n, row, col)) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  cout << row << endl;
  queue<int> rest;
  rep(i, n) rest.push(i+1);
  vector<queue<int> > ques(row);
  rep(i, row) {
    cout << col << ' ';
    rep(j, col-i) {
      int r = rest.front(); rest.pop();
      cout << r << ' ';
      ques[i].push(r);
    }
    rep(j, i) {
      if (ques[j].empty()) continue;
      int r = ques[j].front(); ques[j].pop();
      cout << r << ' ';
      ques[i].push(r);
    }
    cout << endl;
  }
  
  return 0;
}
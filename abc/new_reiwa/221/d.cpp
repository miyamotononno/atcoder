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
const int INF = 2e9;
int n;
int startD[200004], endD[200004];
struct node{int cnt, day;};
int ans[200004];

int main() {
  INCANT;
  cin >> n;
  int a, b;
  rep(i, n) {
    cin >> a >> b;
    startD[i] = a;
    endD[i] = a+b;
  }
  sort(startD, startD+n);
  sort(endD, endD+n);
  // startDとendDから増減を調べる
  int s, e;
  s = e = 0;
  vector<node> diff;
  int cnt = 0;
  while (s < n || e < n) {
    if (s<n && startD[s] == endD[e]) {
      s++;e++;
      continue;
    }
    
    if (s<n && startD[s] < endD[e]) {
      cnt++;
      node n;
      n.cnt = cnt;
      n.day = startD[s];
      diff.push_back(n);
      s++;
      continue;
    }
    if (s ==n || startD[s] > endD[e]) {
      cnt--;
      node n;
      n.cnt = cnt;
      n.day = endD[e];
      diff.push_back(n);
      e++;
      continue;
    }
  }
  for  (int i=1; i < diff.size(); i++) {
    int day = diff[i].day - diff[i-1].day;
    ans[diff[i-1].cnt] += day;
  }
  for (int i=1; i<=n; i++) {
    cout << ans[i];
    if (i==n) cout << endl;
    else cout << ' ';
  }
  
  return 0;
}
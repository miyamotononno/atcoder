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
#include <deque>
#include <unordered_map>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
int Q;
string S;
deque<char> D;
struct edge{bool mae; char c;};

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  rep(i, S.size()) {
    D.push_back(S[i]);
  }
  cin >> Q;
  int a,f;
  int cnt = 0;
  char c;
  vector<edge> V;
  rep(i, Q) {
    cin >> a;
    if (a==1) {
      cnt++;
    } else {
      cin >> f >> c;
      f+=cnt%2;
      f%=2;
      V.push_back({f==0, c});
    }
  }
  rep(i, Q-cnt) {
    edge e = V[i];
    if (e.mae) D.push_back(e.c);
    else D.push_front(e.c);
  }
  cnt%=2;
  if (cnt>0) {
    while(!D.empty()) {
      char d = D.back(); D.pop_back();
      cout << d;
    }
  }else {
    while(!D.empty()) {
      char d = D.front(); D.pop_front();
      cout << d;
    }
  }
  cout << "\n";
  return 0;
}
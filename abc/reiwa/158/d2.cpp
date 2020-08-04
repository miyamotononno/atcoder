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
#include <unordered_map>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int Q;
string S;
struct edge{bool hanten, f; char c;};

void calc(bool hanten, bool mae, char c) {
  // 反転がない場合、mae?前:後ろ
  // 反転がある場合、mae?後ろ:前
  if ((hanten && mae) || (!hanten && !mae)) S.insert(S.end(), c);
  else S.insert(S.begin(), c);
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S >> Q;
  int a,f;
  int cnt = 0;
  char c;
  vector<edge> V;
  rep(i, Q) {
    cin >> a;
    if (a==1) {
      cnt++;
    }
    else {
      cin >> f >> c;
      if (cnt%2>0) {
        V.push_back({true, f==1, c});
      } else {
        V.push_back({false, f==1, c});
      }
    }
  }
  rep(i, Q-cnt) {
    edge e = V[i];
    calc(e.hanten, e.f, e.c);
  }
  cnt%=2;
  if (cnt>0) reverse(ALL(S));
  cout << S << "\n";
  return 0;
}

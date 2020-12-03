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
int n, q;
int S[500002];
set<int> D[26]; 

void update(int l, int c) {
  auto itr = D[S[l]].lower_bound(l);
  D[S[l]].erase(itr);
  D[c].insert(l);
  S[l]=c;
}

int main() {
  INCANT;
  cin >> n;
  char c;
  rep(i, n) {
    cin >> c;
    S[i] = c - 'a';
    D[S[i]].insert(i);
  }
  cin >> q;
  int com;
  vector<int> ans;
  rep(i, q) {
    cin >> com;
    if (com==1) {
      int l;char c;
      cin >> l >> c;
      l--;
      update(l, c-'a');
    } else {
      int l,r;
      cin >> l >> r;
      l--;r--;
      int cnt=0;
      rep(j, 26) {
        auto itr1 = D[j].lower_bound(l);
        auto itr2 = D[j].upper_bound(r);
        cnt+=itr1!=itr2;
      }
      ans.push_back(cnt);
    }
  }

  for (auto c: ans) {
    cout << c << endl;
  }
  return 0;
}
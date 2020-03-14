#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
priority_queue<string, vector<string>, greater<string>> a[10];
int N;
set<char> S;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  a[0].push("a");
  S.insert('a');
  rep(i, N) {
    if (i==0) continue;
    priority_queue<string, vector<string>, greater<string>> que = a[i-1];
    while(!que.empty()) {
      string s = que.top(); que.pop();
      set<char> st;
      rep(i, s.size()) st.insert(s[i]);
      for (auto it = st.begin(); it != st.end(); ++it) {
        char k = *it;
        a[i].push(s+k);
      }
      auto itr = st.end();itr--;
      char c = *itr+1;
      a[i].push(s+c);
      if (que.empty()) S.insert(c);
    }
  }

  priority_queue<string, vector<string>, greater<string>> que2 = a[N-1];
  set<string> Ans;
  while(!que2.empty()) {
    string s = que2.top(); que2.pop();
    Ans.insert(s);
  }
  for (auto it = Ans.begin(); it != Ans.end(); ++it) cout << *it << endl;
  return 0;
}
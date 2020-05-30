#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <deque>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int Q;
int Query[100001][3];
typedef pair<int, int> P;
deque<P> que;

ll calc_energy(ll d[26]) {
  ll ret=0ll;
  rep(i, 26) ret+=pow(d[i], 2);
  return ret;
}

int main() {
  INCANT;
  cin >> Q;
  char c;
  rep(i, Q) {
    cin >> Query[i][0];
    if (Query[i][0]==1) {
      cin >> c >> Query[i][2];
      Query[i][1] = c-'a';
    } else cin >> Query[i][2];
  }
  rep(i, Q) {
    if (Query[i][0]==1) {
      if (!que.empty() && que.back().first == Query[i][1]) {
        P p = que.back();
        que.pop_back();
        p.second+= Query[i][2];
        que.push_back(p);
      } else {
        que.push_back(P(Query[i][1], Query[i][2]));
      }
    } else {
      if (que.empty()) {
        cout << 0 << endl;
        continue; 
      }
      int d = Query[i][2];
      ll energy[26];
      fill(energy, energy+26, 0ll);
      while(!que.empty()) {
        P p = que.front(); que.pop_front(); 
        if (p.second >= d) {
          energy[p.first] += (ll)d;
          if (p.second > d) {
            P n = P(p.first, p.second-d);
            que.push_front(n);
          }
          d=0;
          break;
        } else {
          energy[p.first] += (ll)p.second;
          d-= p.second;
        }
      }
      cout << calc_energy(energy) << endl;
    }
  }

  return 0;
}
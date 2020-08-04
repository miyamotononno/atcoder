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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, M;
typedef pair<int, pair<int, int> > P;
P B[100005];
unordered_map<int, int> Um;
P Ans[100005];

int main() {
  INCANT;
  cin >> N >> M;
  int p,y;
  rep(i, M) {
    cin >> p >> y;
    B[i]=P(y, make_pair(p, i));
  }
  sort(B,B+M);
  rep(i, M) {
    P p =B[i];
    int state = p.second.first;
    Um[state]++;
    int d = Um[state];
    Ans[i] = P(p.second.second, make_pair(state, d));
  }
  sort(Ans, Ans+M);
  rep(i, M) {
    P p = Ans[i];
    cout << setfill('0') << right << setw(6) << p.second.first;
    cout << setfill('0') << right << setw(6) << p.second.second << endl;
  } 
  return 0;
}
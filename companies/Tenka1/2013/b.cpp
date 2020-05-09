#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <stack>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int Q;
ll L;
typedef pair<ll, ll> P;
string Query[100005];
ll QueryInt[100005][2];
stack<P> S;
string STATUS[3] = {"SAFE", "EMPTY", "FULL"};

void input() {
  string s;
  rep(i, Q) {
    cin >> s;
    Query[i] = s;
    ll n,m;
    if (s=="Push") {
      cin >> n >> m;
      QueryInt[i][0] =n;
      QueryInt[i][1] =m;
    }
    if (s=="Pop") {
      cin >> n;
      QueryInt[i][0] =n;
    }
  }
}

int main() {
  INCANT;
  cin >> Q >> L;
  ll SIZE=0ll;
  ll TOP=0ll;
  int status=0;
  input();
  rep(i, Q) {
    string s = Query[i];
    if (s=="Top") {
      if (SIZE==0) {
        status=1;
        break;
      }
      cout << TOP << endl;
    } else if (s=="Size") cout << SIZE << endl;
    
    ll n = QueryInt[i][0];
    ll m = QueryInt[i][1];
    if (s=="Push") {
      SIZE+=n;
      if (SIZE>L) {
        status=2;
        break;
      }
      TOP=m;
      S.push(P(n,m));
    } else if (s=="Pop") {
      if (SIZE<n) {
        status=1;
        break;
      }
      P p = S.top();
      while(p.first < n) {
        S.pop();
        n-=p.first;
        SIZE-=p.first;
        p = S.top();
      }
      SIZE-=n;
      S.pop();
      if (p.first-n>0) S.push(P(p.first-n,p.second));
      if (!S.empty()) TOP=S.top().second;
    }
  }
  cout << STATUS[status] << endl;
  return 0;
}
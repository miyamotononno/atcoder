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
int N;
string S;
vector<int> A;
// ex. (()) は2,-2とする
queue<string> que;

bool check(string T) {
  for (int i=0; i<=T.size()-N+1; i++) {
    int idx  =T.substr(i, N).compare(S);
    if (!idx) return true;
  }
  return false;
}

string calc() {
  string s = "()";
  que.push(s);
  while(!que.empty()) {
    string t = que.front(); que.pop();
    if (t.size()>2*N) continue;
    if (t.size()>= N) {
      cout << t << endl;
      if (check(t)) return t;
    }
    string n1 = "(";
    n1+=t;
    n1+=')';
    que.push(n1);
    string n2="()";
    n2+=t;
    que.push(n2);
    que.push(t+=n2);
  }
  return "NG";
}

int main() {
  INCANT;
  cin >> N >> S;
  int cnt=0;
  string s = calc();
  cout << s << endl;
  return 0;
}
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
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n;
string s;
typedef pair<int, int> P;
int Ans[100005];

void calc(P sec, int rl) {
  // sec.first, rl, rl+1, sec.secondの順
  int start = sec.first;
  int goal = sec.second;
  // goalからstartまでの間のeven or oddとrlとrl+1のそれに集中
  for (int i = start; i<=goal; i++) {
    if ((i-rl)%2==0) Ans[rl]++;
    else Ans[rl+1]++;
  }
}

int main() {
  INCANT;
  cin >> s;
  n = s.size();
  queue<int> RL;
  vector<int> LR;
  rep(i, n-1) {
    if (s[i] == 'R' && s[i+1] == 'L') RL.push(i);
    if (s[i] == 'L' && s[i+1] == 'R') LR.push_back(i);
  }

  vector<P> Sec;
  if (LR.size()==0) {
    Sec.push_back(P(0, n-1));
  } else {
    int start = 0;
    for (auto c: LR) {
      Sec.push_back(P(start,c));
      start = c+1;
    }
    Sec.push_back(P(start, n-1));
  }

  for (auto sec: Sec) {    
    calc(sec, RL.front());
    RL.pop();
  }

  rep(i, n) cout << Ans[i] << ' ';
  cout << endl;

  return 0;
}
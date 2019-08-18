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
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
string S;
int cnt;
string now, pre;

int check_count(string s){
  int trgt = 0;
  while (trgt < s.size()){
    now += s[trgt];
    if (now != pre){
      pre = now;
      now = "";
      cnt++; trgt++;
      continue;
    }
    trgt++;
  }

  if (now == pre) return cnt--;
  return cnt;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  cnt = 0;
  pre = "";
  int ans1 =check_count(S);
  if (S.size() == 1) {
    cout << 1 << endl;
    return 0;
  }
  pre = "";
  string T = S.substr(2, S.size()-2);
  cnt=1;
  int ans2 = check_count(T);
  cout << max(ans1, ans2) <<endl;

  return 0;
}
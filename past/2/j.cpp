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
vector<string> T;

string trans(string s) { // s = ( + t + )の形
  if (s.size()==2) return "";
  string tmp = s.substr(1, s.size()-2);
  string rtmp = s.substr(1, s.size()-2);
  reverse(ALL(rtmp));
  return tmp+rtmp;
}

string dfs(string T) {
  int cnt_1 = 0; // (の個数
  int cnt_2 = 0; // )の個数
  string ret = "";
  string tmp = "";
  rep(i, T.size()) {
    if (T[i]=='(') {
      cnt_1++;
      tmp += '(';
    }
    else if (T[i]==')') {
      cnt_2++;
      tmp+=')';
      if (cnt_1==cnt_2) {
        if (cnt_1==1) ret+=trans(tmp);
        else {
          string n = tmp.substr(1,tmp.size()-2);
          string tmp2 = "";
          tmp2+= '(';
          tmp2+=dfs(n);
          tmp2+=')';
          ret += trans(tmp2);
        }
        tmp="";
        cnt_1=0;
        cnt_2=0;
      }
    }
    else {
      if (cnt_1==0) ret+=T[i];
      else tmp+=T[i];
    }
  }
  return ret;
}

int main() {
  INCANT;
  cin >> S;

  cout << dfs(S) << "\n";
  return 0;
}
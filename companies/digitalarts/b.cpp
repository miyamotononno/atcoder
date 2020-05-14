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
string S,Ans;
map<int, int> M;

bool dfs(int idx, int rest, char pre, string T) {
  if (idx>0) T+=pre;
  if (rest==0) {
    bool flag = false;
    rep(i, S.size()) {
      if (S[i]!=T[i]) { 
        flag = true;
        break;
      }
    }
    if (flag) {
      rep(i, T.size()) Ans+=T[i];
    }
    return flag;
  }
  if (idx>=20) return false;
  for (int i=min(25, rest); i>=0; i--) {
    bool flag = dfs(idx+1, rest-i-1, char(i+'a'), T);
    if (flag) return true;
  }
  return false;
}

int main() {
  INCANT;
  cin >> S;
  int hash_num=0;
  rep(i, S.size()) hash_num+=S[i]-'a'+1;
  
  if (hash_num==1 || hash_num==520) {
    cout << "NO" << endl;
    return 0;
  }
  string T="";
  dfs(0, hash_num, '-', T);
  cout << Ans << endl;
  return 0;
}
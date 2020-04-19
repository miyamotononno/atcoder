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
int A, B;
string S;

int stringToInt(string s){
  int res = 0;
  rep(i, s.size()){
    int a = s[i] - '0';
    res = res*10+a;
  }
  return res;
}

int main() {
  INCANT;
  cin >> A >> B;
  cin >> S;
  rep(i, A) {
    if (S[i]-'0'<0 || S[i]-'0'>9) {
      cout << "No" << endl;
      return 0;
    } 
  }
  if (S[A]!='-') {
    cout << "No" << endl;
    return 0;
  }
  rep(i, B) {
    if (S[i+1+A]-'0'<0 || S[i+1+A]-'0'>9) {
      cout << "No" << endl;
      return 0;
    } 
  }
  cout << "Yes" << endl;
  return 0;
}
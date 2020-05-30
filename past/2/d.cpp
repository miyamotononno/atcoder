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
set<string> L1;
set<char> L2;

int main() {
  INCANT;
  cin >> S;
  N = S.size();
  L2.insert('.');
  rep(i, N) L2.insert(S[i]);  
  if (N==1) {
    cout << L2.size() << endl;
    return 0;
  }
  if (N>1) L1.insert("..");
  rep(i, N-1) {
    string t = "";
    t+=S[i];
    t+=S[i+1];
    L1.insert(t);
    t[0] ='.';
    L1.insert(t);
    t[0] = S[i];
    t[1] = '.';
    L1.insert(t);
  }
  if (N==2) {
    cout << L1.size()+L2.size() << endl;
    return 0;
  }
  L1.insert("...");
  rep(i, N-2) {
    string t = "";
    t+=S[i];
    t+=S[i+1];
    t+=S[i+2];
    L1.insert(t); // abc
    t[0] ='.';
    L1.insert(t); // .bc
    t[1] = '.';
    L1.insert(t); // ..c
    t[0] = S[i];
    L1.insert(t); // a.c
    t[2] = '.';
    L1.insert(t); // a..
    t[1] = S[i+1];
    L1.insert(t); // ab.
    t[0] = '.';
    L1.insert(t); // .b.
  }

  cout << L1.size()+L2.size() << "\n";
  return 0;
}
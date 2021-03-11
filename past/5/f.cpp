#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
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
int n, m;
int A[400], B[400], C[400];
bool D[15][15][15];

bool calc(vector<int> E) {
  if (E.size()<=2) return true;
  for (int i=0; i< E.size()-2;i++) {
    for (int j=i+1; j<E.size()-1;j++) {
      for (int k=j+1; k<E.size();k++) {
        if (D[E[i]][E[j]][E[k]]) return false; 
      }
    }
  }
  return true;
}

bool calc2(vector<int> E, int e) {
  E.push_back(e);
  if (E.size()<=2) return false;
  for (int i=0; i< E.size()-2;i++) {
    for (int j=i+1; j<E.size()-1;j++) {
      for (int k=j+1; k<E.size();k++) {
        if (D[E[i]][E[j]][E[k]]) return true; 
      }
    }
  }
  return false;
}

int main() {
  INCANT;
  cin >> n >> m;
  rep(i, m) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--; B[i]--; C[i]--;
    D[A[i]][B[i]][C[i]] = true;
    D[A[i]][C[i]][B[i]] = true;
    D[B[i]][A[i]][C[i]] = true;
    D[B[i]][C[i]][A[i]] = true;
    D[C[i]][A[i]][B[i]] = true;
    D[C[i]][B[i]][A[i]] = true;
  }
  int ans = 0;
  rep(i, 1<<n) {
    vector<int> kouho;
    rep(bit, n) {
      if (i & (1<<bit)) kouho.push_back(bit);
    }
    if (calc(kouho)) {
      int tmp = 0;
      rep(bit, n) {
        if (!(i & (1<<bit))) { // 現在入っていないものを加え、
          if (calc2(kouho, bit)) tmp++;
        }
      }
      ans = max(tmp, ans);
    }
  }
  
  cout << ans << "\n";
  return 0;
}
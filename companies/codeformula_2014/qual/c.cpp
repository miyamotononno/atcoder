#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
string A,B;
map<char, int> M1, M2;
typedef pair<int, int> P;

void calc(vector<P> &vec, int n) {
  for (int i=0; i<n-1; i++) {
    for (int j=0; j<n; j++) {
      vec.push_back(P(i, j));
    }
  }
}

int main() {
  INCANT;
  cin >> A >> B;
  int n = A.size();
  set<int> S;
  rep(i, n) {
    M1[A[i]]++;
    M2[B[i]]++;
    S.insert(A[i]);
  }
  for(auto p: M1) {
    if (M2[p.first] != p.second) {
      cout << "NO" << endl;
      return 0;
    }
  }
  int cnt=0;
  rep(i, n) {
    if (A[i]!=B[i]) cnt++;
  }

  if (cnt>6) {
    cout << "NO" << "\n";
    return 0;
  }

  if (S.size() == n && (cnt==0 || cnt==4)) {
    cout << "NO" << "\n";
    return 0;
  }
  if (n>26) {
    cout << "YES" << endl;
    return 0;
  }
  vector<int> W(n);
  rep(i, n) W[i]=A[i];
  vector<P> vec1,vec2,vec3;
  calc(vec1, n);
  calc(vec2, n);
  calc(vec3, n);
  for (auto p1: vec1) {
    for (auto p2: vec2) {
      for (auto p3: vec3) {
        swap(W[p1.first], W[p1.second]);
        swap(W[p3.first], W[p2.second]);
        swap(W[p3.first], W[p3.second]);
        rep(i, n) {
          if (W[i]!=B[i]) break;
          if (i==n-1) {
            cout << "YES" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "NO" << "\n";
  return 0;

  return 0;
}

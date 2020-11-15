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
int N, K;
unordered_map<string, int> S;
vector<string> A[100005];

int main() {
  INCANT;
  cin >> N >> K;
  string s;
  rep(i, N) {
    cin >> s;
    S[s]++;
  }
  for (auto p: S) A[p.second].push_back(p.first);
  int idx = 0;
  for (int i=N; i>=1; i--) {
    if (idx>=K) {
      cout << "AMBIGUOUS" << endl;
      return 0;
    }
    if (idx==K-1 && A[i].size()==1) {
      cout << A[i][0] << endl;
      return 0;
    }
    idx+=A[i].size();
  }
  cout << "AMBIGUOUS" << endl;
  return 0;
}
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
int n;
unordered_map<int, int> U; // 値: 場所

int main() {
  INCANT;
  cin >> n;
  vector<int> A(n); // その場所に今何があるか
  int a;
  rep(i, n) {
    cin >> a;
    A[i] = a-1;
    U[a-1] = i;
  }
  int pre = 0;
  vector<int> ans;
  while(pre<n-1) {
    if (A[pre]==pre) {
      pre++;
      continue;
    }
    for(int j=U[pre]-1; j>=pre; j--) {
      swap(A[j], A[j+1]);
      ans.push_back(j);
    }
    for (int j=pre; j<U[pre]; j++) {
      if (A[j]!=j) {
        cout << -1 << endl;
        return 0;
      }
    }
    pre = U[pre];
  }

  if (ans.size()!=n-1) {
    cout << -1 << endl;
    return 0;
  }
  for (auto p: ans) {
    cout << p+1 << endl;
  }

  return 0;
}
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
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
int A[100005];
vector<int> vec;

int binary_search(int v) { // v未満のものがないなら-1
  if (vec.size()==1) {
    if (vec[0]<v) return 0;
    return 1;
  }
  int l = -1;
  int r = vec.size();
  // vec[l] > vec[r]に注意
  while(r-l>1) {
    int mid = (l+r)/2;
    if (vec[mid]<v) { // midの制限をきつくしても良い
      r = mid;
    } else l = mid;
  }
  return r;
}

int main() {
  INCANT;
  cin >> n;
  rep(i, n) cin >> A[i];
  vec.push_back(A[0]);
  for (int i=1; i<n; i++) {
    bool ok = false;
    int idx= binary_search(A[i]);
    if (idx < vec.size()) {
      vec[idx] = A[i];
    } else vec.push_back(A[i]);
  }
  
  cout << vec.size() << "\n";
  return 0;
}
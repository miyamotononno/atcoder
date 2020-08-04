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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
int N;
vector<int> A;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int a;
  rep(i, N){
    cin >> a;
    A.push_back(a);
  }
  
  sort(A.begin(), A.end());
  int ans1 = A[N-1];
  int medi = A[N-1]/2;
  auto po = lower_bound(A.begin(), A.end(), medi);
  int s = po-A.begin();

  if (A[s] == medi){
    cout << ans1 << ' ' << medi << endl;
    return 0;
  }

  if (A[s] - medi > medi - A[s-1]){
    cout << ans1 << ' ' << A[s-1] << endl;
  } else {
    if (A[s] == ans1){
      cout << ans1 << ' ' << A[s-1] << endl;
    }else{
      cout << ans1 << ' ' << A[s] << endl;
    }
  }

  return 0;
}
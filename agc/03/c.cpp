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
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
typedef pair<int, int> P;
int N;
vector<P> A;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int a;
  rep(i, N){
    cin >> a;
    P p = make_pair(a, i%2);
    A.push_back(p);
  }
  sort(A.begin(), A.end());

  int cnt=0;
  rep(i, N){
    int v = A[i].second;
    if (i%2!=v){
      cnt++;
    }
  }
  cout << cnt/2 << "\n";
  return 0;
}
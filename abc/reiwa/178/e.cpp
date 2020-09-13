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
#include <deque>
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
int N;
int A[200005], B[200005];


int main() {
  INCANT;
  cin >> N;
  int a,b;
  rep(i, N) {
    cin >> a >> b;
    A[i] = a+b;
    B[i] = a-b;
  }
  sort(A, A+N);
  sort(B, B+N);
  
  cout << max(A[N-1]-A[0], B[N-1]-B[0]) << endl;
  
  return 0;
}
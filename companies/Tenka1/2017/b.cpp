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
typedef pair<int, int> P;
P A[100004];

int main() {
  INCANT;
  cin >> N;
  int a,b;
  rep(i, N) {
    cin >> a >> b;
    A[i]=P(a,b);
  }
  sort(A, A+N, greater<P>());
  cout << A[0].first+A[0].second << endl;
  return 0;
}
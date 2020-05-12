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
const int INF = 2e9;
int N, T;
int A[100005];
int MIN[100005], MAX[100005];

int main() {
  INCANT;
  cin >> N >> T;
  rep(i, N) cin >> A[i];
  
  MIN[0]=A[0];
  rep(i, N) {
    if (i==0) continue;
    MIN[i]=min(A[i], MIN[i-1]);
  }
  MAX[N-1]=A[N-1];
  for (int i=N-2; i>=0; i--) MAX[i] = max(MAX[i+1], A[i]);
  int diff=0;
  rep(i, N) diff = max(MAX[i]-MIN[i], diff);
  int cnt=0;
  rep(i, N) if (MAX[i]-A[i]==diff) cnt++;

  cout << cnt << "\n";
  return 0;
}
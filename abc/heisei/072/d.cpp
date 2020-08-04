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
int N, A[100005];

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> A[i];
  
  int cnt = 0;
  bool flag = false;
  rep(i, N) {
    if (A[i]==i+1) {
      if (flag) {
        cnt++;
        flag =false;
      } else flag =true;
    } else {
      if (flag) cnt++;
      flag = false;
    }
  }
  if (flag) cnt++;

  cout << cnt << "\n";
  return 0;
}
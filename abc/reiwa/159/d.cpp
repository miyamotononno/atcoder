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
int N,A[200005];
ll Cnt[200005];

int main() {
  INCANT;
  cin >> N;
  int a;
  rep(i, N) {
    cin >>a;
    a--;
    A[i]=a;
    Cnt[a]++; //0-index
  }
  ll sm = 0ll;
  rep(i,N) {
    sm+=Cnt[i]*(Cnt[i]-1)/2;
  }
  // ex. -6*5/2+5*4/2 = -5
  rep(i, N) {
    cout << sm - (Cnt[A[i]]-1) << "\n";
  }
  return 0;
}
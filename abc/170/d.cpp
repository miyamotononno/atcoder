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
const int MAX_A = 1e6+10;
const int MAX_N = 2e5;
bool is_prime[MAX_A];
int A[MAX_N];

void init() {
  rep(i, MAX_A) is_prime[i]=true;
  is_prime[0]=false;
}

int main() {
  INCANT;
  init();
  cin >> N;
  rep(i, N) cin >> A[i];
  sort(A, A+N);
  int cnt=0;
  rep(i, N) {
    if (is_prime[A[i]]) {
      if (i<N-1 && A[i]==A[i+1]) cnt-=1;
      cnt++;
      for (int j=A[i]; j <= MAX_A; j+=A[i]) is_prime[j] = false;
    }
  }
  cout << cnt << endl;
}
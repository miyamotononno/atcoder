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
ll dp[10000003];
bool searched[10000003];

bool is_prime[10000001+1];
vector<int> prime;

void sieve(int n){
  for (int i=0; i <= n; i++) is_prime[i]=true;
  is_prime[0]=is_prime[1]=false;
  for (int i = 2; i <= n; i++){
    if (is_prime[i]){
      for (int j=2*i; j <= n; j+=i) is_prime[j] = false;
    }
  }
  rep(i, n+1) {
    if (is_prime[i]) prime.push_back(i);
  }
}

bool calc(ll a, ll key) { // keyは素因数
  if (key*a>N) return true;
  if (searched[key*a]) return false;
  ll _a = a;
  ll cnt=1;
  while(_a%key==0) {
    _a/=key;
    cnt++;
  }
  dp[key*a] = dp[a]*key*(cnt+1)/cnt;
  searched[key*a] = true;
  return false;
}

int main() {
  INCANT;
  cin >> N;
  sieve(N);
  dp[1] = 1ll;
  for (int i=1; i<=N; i++) {    
    for (auto p: prime) {
      if (calc(i, p)) break;
    }
    searched[i] = true;
  }
  ll sum=0ll;
  for (int i=1ll; i<=N; i++) sum+=dp[i];
  cout << sum << endl;
  return 0;
}
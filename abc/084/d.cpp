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
int N;
int A[100001];
int prime[100000];
bool is_prime[100001];
bool is_2017[100001];
int S[100001];
int Q;

void sieve(int n){
  int p = 0;
  for (int i=0; i <= n; i++) is_prime[i]=true;
  is_prime[0]=is_prime[1]=false;
  for (int i = 2; i <= n; i++){
    if (is_prime[i]){
      prime[p++] = i;
      for (int j=2*i; j <= n; j+=i) is_prime[j] = false;
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  sieve(110000);
  rep(i, 110000){
    is_2017[i] = false;
    if (is_prime[i] && is_prime[(i+1)/2]){
      is_2017[i] = true;
    }
  }
  rep(i, 100000){
    if (is_2017[i+1]){
      S[i+1] = S[i]+1; 
    } else S[i+1] = S[i];
  }

  cin >> Q;
  int a, b;
  rep(i, Q){
    cin >> a >> b;
    cout << S[b] - S[a-1] << "\n";
  }
  return 0;
}
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
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
int A[100001];


// その他　便利機能
#define index_of(as, x) distance(as.begin(), lower_bound(as.begin(), as.end(), x))
typedef pair<int, int> P;
vector<P> O;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
// Fill(d, 3); 多次元配列でも対応可能


// gcd lcm
ll calc_gcd(ll a, ll b) {
    if (b == 0) return a;
    return calc_gcd(b, a % b);
}

ll calc_lcm(ll a, ll b) {
    ll g = calc_gcd(a, b);
    return a / g * b;
}

// numのpow乗をmodで計算する
ll pow_mod(ll num, ll pow, ll mod) {
    ll prod = 1;
    num %= mod;
    while (pow > 0) {
        if (pow & 1) prod = prod * num % mod;
        num = num * num % mod;
        pow >>= 1;
    }
    return prod;
}

// nCrを求める
void comb(vector<vector <long long int> > &v){
  for(int i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int k = 1;k <v.size();k++){
    for(int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
}

// 素数判定
bool IsPrime(int num){
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2){
    if (num % i == 0)return false;
  }
  return true;
}

int stringToInt(string s){
  int res = 0;
  rep(i, s.size()){
    int a = s[i] - '0';
    res = res*10+a;
  }
  return res;
}
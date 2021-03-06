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
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
typedef pair<ll, ll> P;


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


// nPc. nCc = nPc/c!なのでnが膨大なときはこれを使う
ll kaizyo(ll a, int c) {
  ll b = 1;
  rep(i, c) {
    b *= a;
    b%=MOD;
    a--;
  }
  return b;
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


// 3つの格子点を結んだ三角形の面積が整数がどうか
// 三角形の面積を求めたいならばdoubleに変更し、double_area/2を出力すること
bool triangle_area(P p1, P p2, P p3) {
  ll x = p3.first-p1.first;
  if (!x) return false;
  ll double_area = p1.second*(p3.first-p2.first) + p3.second*(p2.first-p1.first) - p2.second*x;
  return double_area && double_area%2==0;
}
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
int N, K;
ll A[200005];

ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
ll modinv(ll a) {
    return modpow(a, MOD - 2);
}

ll formatMOD(ll a) {
  if (a<0) a+=MOD;
  return a;
}

int main() {
  INCANT;
  ifstream qfile("./random_pm00.txt");
  bool nega=true;
  ll num;
  int cnt=0;
  while(qfile >> num) {
    if (cnt==0) N = num;
    else if (cnt==1) K = num;
    else {
      if (num >= 0) nega=false;
      A[cnt-2] = num;
    }
    cnt++;
  }

  sort(A, A+N,  [&](ll a, ll b) { return abs(a) > abs(b); }); // 絶対値で降順
  ll ret=1ll;
  if (nega&&K%2 || (N==K)) {
    for (int i=N-1;i>=N-K;i--) {
      ret*=A[i];
      ret%=MOD;
    }
    cout << formatMOD(ret) << endl;
    return 0;
  }

  bool fl=true;
  ll x1,x2,y1,y2;
  x1=x2=-1ll;y1=y2=1ll; //x>=0, y<0
  rep(i, K) {
    if (A[i]<0) {
      fl = !fl;
      y1 = A[i];
    } else x1 = A[i];
    ret*=A[i];
    ret%=MOD;
  }
  if (x1==0) {
    cout << 0 << endl;
    return 0;
  } 
  if (fl) {
    cout << formatMOD(ret) << endl;
    return 0;
  }
  // この段階で降順K個の積は負
  for (int i=K; i<N; i++) {
    if (A[i]>=0 && x2<0) x2 = A[i];
    else if (A[i]<0 && y2>0) y2=A[i];
  }
  ll ans1 = ret*modinv(y1)%MOD*x2%MOD;
  ll ans2 = ret*modinv(x1)%MOD*y2%MOD;
  if (y2>0 || x1<0) {
    cout << formatMOD(ans1) << endl;
  } else if (x2<0) {
    cout << formatMOD(ans2) << endl;
  } else {
    // x2/y1 < y2/x1 <=> x2*x1 > y2*y1 (両辺かけるのが負なので)
    ll ans = x1*x2 > y1*y2?ans1:ans2;
    cout << formatMOD(ans) << endl;
  }

  return 0;
}
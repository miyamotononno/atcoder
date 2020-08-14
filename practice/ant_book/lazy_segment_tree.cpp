using namespace std;
#include <iostream>
#define rep(i, n) for(int i=0;i<n;i++)
typedef long long ll;
const int INF = 2e9;
const int MAX_N = 1 << 17;
const int DAT_SIZE = (1<<18)-1;

int N,Q;
int A[MAX_N];
// セグメント木
int dat1[DAT_SIZE];
int dat2[DAT_SIZE];

// [a,b)にxを加算する
// kは節点の番号で、区間[l,r)に対応する
void add(int a, int b, int x, int k, int l, int r) {
  if (a<=l && r <=b) {
    dat1[k]+=x;
  } else if (l < b && a < r){
    dat2[k] += (min(b,r)-min(a,l))*x;
    add(a,b,x,k*2+1,l,(l+r)/2);
    add(a,b,x,k*2+2,(l+r)/2,r);
  }
}

// [a,b)の和を計算する
// kは節点の番号で、区間[l,r)に対応する
int sum(int a, int b, int k, int l, int r) {
  if (b<=l || a>=r) return 0;
  else if (a <= l && r<= b) return dat1[k]*(r-1)+dat2[k];
  else {
    ll res = (min(b, r)-max(a, l))*dat1[k];
    res+=sum(a,b,k*2+1,l,(l+r)/2);
    res+=sum(a,b,k*2+2,(l+r)/2,r);
    return res;
  }
}

void solve() {
  rep(i, N) add(i,i+1, A[i], 0,0,N);
  char query=' '; // Cで足す、それ以外で和の計算
  int l,r,x;
  rep(i, Q) {
    if (query=='C') add(l,r,x,0,0,N);
    else cout << sum(l,r+1,0,0,N) << endl;
  }
}
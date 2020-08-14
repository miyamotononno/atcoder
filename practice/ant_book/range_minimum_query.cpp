using namespace std;
#include <iostream>
#define rep(i, n) for(int i=0;i<n;i++)
const int INF = 2e9;
const int MAX_N = 1 << 17;

// セグメント木を持つグローバル配列
int n, dat[2*MAX_N-1];

void init(int n_) {
  // 簡単のため、要素数を2の冪乗にする。
  int n=1;
  while(n<n_) n*=2;
  rep(i,2*n-1) dat[i]=INF;
}

// k番目の値をaに変更
void update(int k, int a) {
  // 葉の節点
  k+=n-1;
  dat[k]=a;
  // のぼりながら更新
  while(k>0) {
    k=(k-1)/2;
    dat[k]=min(dat[k*2+1], dat[k*2+2]);
  }
}

// [a,b)の最小値を求める
// kは接点の番号、l,rはその接点が[l,r)に対応づいていることを表す
int query(int a, int b, int k, int l, int r) {
  //[a,b)と[l,r)が交差しなければINT_MAX
  if (r <= a || b <= l) return INF; 
  //[a,b)と[l,r)が完全に含んでいれば、この接点の値
  if (a<=l && r <=b) return dat[k];
  else {
    // そうでなければ二つの子の最小値
    int vl = query(a,b,k*2+1,l, (l+r)/2);
    int vr = query(a,b,k*2+2,(l+r)/2, r);
    return min(vl, vr);
  }
}


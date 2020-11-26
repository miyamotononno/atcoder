#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int n, k;
const int Q=5; // 中央値を求める際にこれ以下のサイズだとsortする. 5以上ならよい
// 配列の中でk番目の大きさの値を取り出す
// O(n)

void init(int A[]) {
  random_device seed_gen;
  default_random_engine engine(seed_gen());

  uniform_int_distribution<> dist(0, 1000);
  rep(i, n) A[i] = dist(engine);
}

void show(int A[], int& target) {
  int B[n];
  rep(i, n) B[i]=A[i]; 
  sort(B, B+n);
  if (n<k) return;
  target = B[k];
}

int sortAndFindKIndex(int B[], int l, int r, int k=-1) {
  sort(B+l, B+r);
  if (k<0) k = (r+l)/2;
  return B[k];
}



int sequentialSelect(int A[], int sz, int k, bool print=false) {
  if (print) {
    cout << "call sequentialSelect" << endl;
    rep(i, sz) cout << A[i] << ' ';
    cout << endl;
  }
  if (sz<=Q) {
    if (print) cout << sz << ' ' << k << endl;
    int m = sortAndFindKIndex(A, 0, sz, k);
    if (print) cout << "m: " << m << endl;
    return m;
  }
  int cNum = sz/Q + 1;
  int medians[cNum];
  rep(i, sz/Q) medians[i] = sortAndFindKIndex(A, Q*i, Q*(i+1));
  
  int lastNum = sz - Q*(sz/Q);
  if (lastNum>0) {
    medians[cNum-1] = sortAndFindKIndex(A, Q*(sz/Q), sz);
  } else cNum--;
  int M = sequentialSelect(medians, cNum, cNum/2, print);
  int leg[3] = {0, 0, 0}; // medianより小さい, 等しい, 大きい
  int marks[sz];
  rep(i, sz) {
    if (A[i]<M) {
      leg[0]++;
      marks[i] = 0;
    }
    else if (A[i]>M) {
      leg[2]++;
      marks[i] = 2;
    }
    else {
      leg[1]++;
      marks[i] = 1;
    }
  }
  if (print) {
    cout <<"M: " << M << endl;
    rep(i, 3) cout << leg[i] << ' ';
    cout << endl;
  }
  if (leg[0]<=k && k<sz-leg[2]) return M;
  int targetIdx, targetZone;
  if (k<leg[0]) {
    targetIdx = k;
    targetZone=0;
  }
  else {
    targetIdx = k - (leg[0]+leg[1]);
    targetZone = 2;
  }
  int newArray[leg[targetZone]];
  int j=0;
  rep(i, sz) if (marks[i]==targetZone) newArray[j++] = A[i];
  
  M = sequentialSelect(newArray, leg[targetZone], targetIdx, print);
  return M;
}

int main() {
  cin >> n >> k;
  int A[n];
  init(A);
  int answer = sequentialSelect(A, n, k);
  cout << answer << endl;
  return 0;
}
#include <iostream>
#include <vector>
using namespace std;


// 10 12 13 9 14
bool findScore(vector<int>& A, int baseSize, int& n, int& l, int& k) {
  int cur = 0;
  int ret = l;
  int cnt = 0;
  for (int i=0; i<=n; i++) {
    cur+=A[i];
    if (cur>=baseSize) {
      cnt++;
      cur=0;
    }
  }
  return cnt>=k+1;
}



int main() {
  int n, l, k;
  cin >> n >> l;
  cin >> k;
  vector<int> B(n),A(n+1);
  for (int i=0; i<n; i++) cin >> B[i];
  A[0]=B[0];
  for (int i=1; i<=n; i++) {
    if (i==n) {
      A[i] = l-B[i-1];
    } else {
      A[i] = B[i]-B[i-1];
    }
  }
  
  int ok = 0;
  int ng = l+1;
  while(ng-ok>1) {
    int mid = (ok+ng)/2;
    bool isExist = findScore(A, mid, n, l, k);
    if (isExist) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}
#include <bits/stdc++.h>
using namespace std;
int H, W;


pair<bool, long long> solve(vector<vector<int>>& A, const vector<vector<int>>& B) {
  pair<bool, long long> p;
  for (int i=0; i<H-1; i++) {
    for (int j=0; j<W-1; j++) {
      // (i,j)の位置から見ていく
      long long d = B[i][j]-A[i][j];
      A[i][j]+=d;
      A[i+1][j]+=d;
      A[i][j+1]+=d;
      A[i+1][j+1]+=d;
      p.second+=abs(d);
    }
  }
  
  for (int i=0; i<H; i++) {
    if (A[i][W-1] != B[i][W-1]) {
      p.first = false;
      return p;   
    } 
  }
  for (int i=0; i<W; i++) {
    if (A[H-1][i] != B[H-1][i]) {
      p.first = false;
      return p;   
    } 
  }
  p.first = true;
  return p;
}

int main() {
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W)), B(H, vector<int>(W));
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> A[i][j];
    }
  }
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> B[i][j];
    }
  }
  pair<bool, long long> ans = solve(A, B);
  
  if (ans.first) {
    cout << "Yes" << endl;
    cout << ans.second << endl;
  } else {
    cout << "No" << endl;
  }
}
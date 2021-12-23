#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int cnt = 0;
  deque<int> deq;
  for (int i=0;i<N;i++) {
    if (S[i]=='0') {
      cnt++;
      deq.push_back(i+1);
    }
  }
  if (cnt==1) {
    cout << -1 << endl;
    return 0;
  }
  // 一つだけずらす
  int d = deq.front(); deq.pop_front();
  deq.push_back(d);
  for (int i=0; i<N; i++) {
    if (S[i]=='1') {
      cout << i+1;
    } else {
      cout << deq.front();
      deq.pop_front();
    }
    if (i==N-1) cout << endl;
    else cout << ' ';
  }
}
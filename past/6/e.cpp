#include <bits/stdc++.h>
using namespace std;


bool isSizeError(const int& size, const deque<int>& deq) {
  if (deq.size()<=size) {
    cout << "ERROR" << endl;
    return true; 
  }
  return false;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  deque<int> deq;
  int f,f1,f2,b,b1,b2; // switch文の中では変数宣言をしてはならない。
  for (int i=0; i<n; i++) {
    switch(s[i]) {
      case 'L':
        deq.push_front(i+1);
        break;
      case 'R':
        deq.push_back(i+1);
        break;
      case 'A':
        if (isSizeError(0, deq)) break;
        cout << deq.front() << endl;
        deq.pop_front();
        break;
      case 'B':
        if (isSizeError(1, deq)) break;
        f = deq.front(); deq.pop_front();
        cout << deq.front() << endl;
        deq.pop_front();
        deq.push_front(f);
        break;
      case 'C':
        if (isSizeError(2, deq)) break;
        f1 = deq.front(); deq.pop_front();
        f2 = deq.front(); deq.pop_front();
        cout << deq.front() << endl;
        deq.pop_front();
        deq.push_front(f2);deq.push_front(f1);
        break;
      case 'D':
        if (isSizeError(0, deq)) break;
        cout << deq.back() << endl;
        deq.pop_back();
        break;
      case 'E':
        if (isSizeError(1, deq)) break;
        b = deq.back(); deq.pop_back();
        cout << deq.back() << endl;
        deq.pop_back();
        deq.push_back(b);
        break;
      case 'F':
        if (isSizeError(2, deq)) break;
        b1 = deq.back(); deq.pop_back();
        b2 = deq.back(); deq.pop_back();
        cout << deq.back() << endl;
        deq.pop_back();
        deq.push_back(b2); deq.push_back(b1);
        break;
    }
  }
}
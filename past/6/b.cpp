#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  for (int i=0; i<S.size(); i+=4) {
    if (S[i+1]=='o') {
      cout << (i/4)+1 << endl;
      return 0;
    }
  }
  cout << "none" << endl;
  return 0;
}
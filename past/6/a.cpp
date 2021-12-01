#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string S;
  cin >> S;
  for (int i=0; i<8; i++) {
    if (i==3) {
      if (S[i]!='-') {
        cout << "No" << endl;
        return 0;
      }
    } else {
      if (S[i]-'0'<0 || S[i]-'0'>9) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}
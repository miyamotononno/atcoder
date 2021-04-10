#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n%2==1) return 0;
  for (int i=0; i<(1<<n); i++) {
    stack<char> st;
    bool ng = false;
    for (int bit=0; bit<n; bit++) {
      if ((1 << bit)&i) st.push('(');
      else {
        if (st.empty()) {
          ng = true;
          break;
        }
        st.pop();
      }
    }
    if (ng || !st.empty()) continue;
    for (int bit=n; bit>=0; bit--) {
      if ((1 << bit)&i) cout << ')';
      else cout << '(';
    }
    cout << endl;
  }

}
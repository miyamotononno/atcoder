#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;
typedef long long ll;
ll N,A,B,C;

int main() {
  cin >> N >> A >> B >> C;
  int ans = 10000;
  for (int a=0; a<=9999; a++) {
    for (int b=0; b<=9999; b++) {
      ll rest = N - a*A - b*B;
      if (rest<0) break;
      if (rest%C==0) {
        int c = rest/C;
        ans = min(ans, a+b+c);
      } 
    }
  }
  cout << ans << endl;
}
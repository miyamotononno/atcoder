#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int N, A, B;

int main() {
  INCANT;
  cin >> N >> A >> B;
  bool flag;
  if (N<=A) flag = true;
  else if (A==B) {
    if (N%(A+1)) flag = true;
    else flag = false;
  }
  else if (A>B) flag = true;
  else  flag = false;
  string ans = flag?"Takahashi":"Aoki";
  cout << ans << endl;
  return 0;
}

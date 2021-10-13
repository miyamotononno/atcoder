#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
typedef long long ll;
ll a, b, c;

// https://twitter.com/e869120/status/1385001057512693762/photo/1
// 誤差について: https://medium-company.com/%E4%B8%B8%E3%82%81%E8%AA%A4%E5%B7%AE-%E6%89%93%E5%88%87%E3%82%8A%E8%AA%A4%E5%B7%AE-%E6%A1%81%E8%90%BD%E3%81%A1-%E6%83%85%E5%A0%B1%E8%90%BD%E3%81%A1-%E9%81%95%E3%81%84/


// std::pow関数は使わないこと！(内部が浮動小数点数で実装されているため丸め誤差が発生する)
ll pow_c_b(ll c, ll b) {
  ll ret=1ll;
  while(b--) ret*=c;
  return ret;
}

int main() {
  cin >> a >>b >> c;
  // a < c^bか？

  if (a < pow_c_b(c, b)) {
    cout << "Yes" << endl;
  } else cout << "No" << endl;
}
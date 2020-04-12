#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
ll t1,t2,a1,a2,b1,b2;

int main() {
  INCANT;
  cin >> t1 >> t2;
  cin >> a1 >> a2;
  cin >> b1 >> b2;
  ll diff1 = (b1-a1)*t1; // bがaに着けた差
  ll diff2 = (b2-a2)*t2;
  if (diff1+diff2==0) {
    cout << "infinity" << "\n";
    return 0;
  }
  if (!((diff1>0ll) ^ (diff1+diff2 >0ll))) {
    cout << 0 << "\n";
    return 0;
  }
  ll diff = abs(diff2)-abs(diff1);
  ll cnt = 1ll; // 初回から最初にt1+t2分経過するまでに1回カウントする
  cnt += 2*(abs(diff1)/abs(diff));
  if (abs(diff1)%diff==0) cnt--; // 最後に会う時は１サイクルのなかで1回しかない

  cout << cnt << "\n";
  return 0;
}
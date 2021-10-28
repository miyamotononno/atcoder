#include <iostream>
using namespace std;
typedef long long ll;
int N;
ll A[101][6];
const ll MOD = 1e9+7;

int main() {
  cin >> N;
  ll ret = 1ll;
  for (int i=0;i<N;i++) {
    ll a;
    ll tmp=0ll;
    for (int j=0; j<6; j++) {
      cin >> a;
      tmp+=a;
    }
    ret*=tmp;
    ret%=MOD;
  }
  cout << ret << endl;
}

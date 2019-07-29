#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
int N;
int P[50];


int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int a;
  int cnt = 0;
  rep(i, N){
    cin >> a;
    a--;
    if (i!=a) cnt++;
  }

  if (cnt<=2) cout << "YES"<< endl;
  else cout << "NO" << endl;
  return 0;
}
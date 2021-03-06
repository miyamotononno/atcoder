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
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i,9) {
    if (N%(i+1) ==0) {
      if (0<N/(i+1)&& N/(i+1)<10) {
        cout << "Yes" << "\n";
        return 0;
      }
    }
  }

  cout << "No" << "\n";
  return 0;
}
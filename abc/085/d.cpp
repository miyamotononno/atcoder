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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int N, H;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> H;
  int a_max = 0;
  int a=0;
  int b=0;
  vector<int> V(N);
  rep(i, N){
    cin >> a >> b;
    a_max = max(a_max, a);
    V[i] = b;
  }
  sort(ALL(V), greater<int>());
  int cnt=0;
  rep(i, N){
    int c = V[i];
    if (a_max>=c) break;
    H-=c;
    cnt++;
    if (H<=0){
      cout << cnt << "\n";
      return 0;
    }
  }

  cnt += (H+a_max-1)/a_max;
  cout << cnt << "\n";
  return 0;
}
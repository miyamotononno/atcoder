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
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
int A[100003];
unordered_map<int, int> M;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int a;
  rep(i, N){
    cin >> a;
    M[a]++;
  }
  int ans=0;
  for (auto it=M.begin(); it !=M.end(); ++it){
    int cnt = it->second;
    if (cnt%2) ans++;
  }
  cout << ans << "\n";
  return 0;
}
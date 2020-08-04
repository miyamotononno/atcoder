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
int N;
string S;
int left_white[200000]; // それ左にある白の個数
int right_red[200000]; // それより右にある赤の個数

void init() {
  if (S[0]=='W') left_white[0] = 1;
  rep(i, N) {
    if (i==0) continue;
    if (S[i]=='W') left_white[i] = left_white[i-1]+1;
    else left_white[i] = left_white[i-1];
  }
  if (S[N-1]=='R') right_red[N-1] = 1;
  for (int i=N-2; i>=0; i--) {
    if (S[i]=='R') right_red[i] = right_red[i+1]+1;
    else right_red[i] = right_red[i+1];
  }

}

int main() {
  INCANT;
  cin >> N >> S;
  init();
  int all_white=0;
  int all_red=0;
  rep(i, N) {
    if (S[i]=='R') all_white++;
    else all_red++;
  }
  int min_cnt = min(all_white, all_red);
  rep(i, N-1) {
    min_cnt = min(max(left_white[i], right_red[i+1]), min_cnt); 
  }
  cout << min_cnt << endl;

  return 0;
}
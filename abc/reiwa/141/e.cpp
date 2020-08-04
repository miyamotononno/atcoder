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

// 文字列Sが与えられた時に、LCP配列を返す
// Zalgoの計算量はO(n), 全体でO(n^2)
vector<int> Zalgo(const string &S) {
  int N = (int)S.size();
  vector<int> res(N);
  res[0] = N;
  int i = 1, j = 0;
  while (i < N) {
    while (i+j < N && S[j] == S[i+j]) ++j;
    res[i] = j;
    if (j == 0) {
      ++i;
      continue;
    }
    int k = 1;
    while (i+k < N && k+res[k] < j) res[i+k] = res[k], ++k;
    i += k, j -= k;
  }
  return res;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  string S;
  cin >> N >> S;

  int res = 0;
  rep(i, N) {
    string T = S.substr(i); // i番目以降の文字列
    auto lcp = Zalgo(T);

    rep(j, T.size()) {
      int l = min(lcp[j], j);
      res = max(res, l);
    }
  }
      
  cout << res << endl;

  return 0;
}
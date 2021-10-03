#include <iostream>
#include <vector>
using namespace std;
int N, K;
string S;
int C[100004][26];
#define rep(i,n) for (int i=0; i<n;++i)

// i以降(i含む)で、文字jについて最も直近にあるもの
void init() {
  for (int i=N; i>=0; i--) {
    for (int j=0; j<26; j++) {
      C[i][j] = N;
    }
  }
  for (int i=N-1; i>=0; i--) {
    for (int j=0; j<26; j++) {
      int c = S[i]-'a';
      if (j == c) C[i][c] = i;
      else C[i][j] = C[i+1][j];
    }
  }
}

int main() {
  cin >> N >> K;
  cin >> S;
  init();
  // 貪欲
  int i = 0;
  string ans = "";
  while (i<N) {
    rep(j, 26) {
      // C[i][j]の文字を選ぶ
      int sz = N - C[i][j] - 1; // C[i][j]以降の文字数
      int needSize = K - ans.size()-1;
      if (sz >= needSize) { // 残りの必要文字数 *sz >= K - ans.size()-1としてはだめ！！！！
        ans += S[C[i][j]];
        if (ans.size()==K) {
          cout << ans << endl;
          return 0;
        }
        i = C[i][j]+1;
        break;
      }
    }
  }
}
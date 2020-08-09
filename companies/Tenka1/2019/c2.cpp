using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#define rep(i, n) for (int i=0; i<n; i++)
int N;
string s;
int w[200005],b[200005];

int main() {
  cin >> N;
  cin >> s;
  int white=0;
  rep(i, N) {
    if (s[i]=='.') white++;
  }
  int cnt = min(white,N-white);
  rep(i, N) { // 自分含めてi番目から左までに黒が何個あるか
    if (i==0) b[0] = s[0]=='#'?1:0;
    else b[i] = s[i]=='#'?b[i-1]+1:b[i-1];
  }
  for(int i=N-1; i>=0; i--) { // 自分含めてi番目から右までに白が何個あるか
    if (i==N-1) w[i] = s[i]=='.'?1:0;
    else w[i] = s[i]=='.'?w[i+1]+1:w[i+1];
  }
  rep(i, N) {
    if (i==0) continue;
    cnt = min(cnt, w[i]+b[i-1]);
  }
  cout << cnt << endl;
  return 0;
}
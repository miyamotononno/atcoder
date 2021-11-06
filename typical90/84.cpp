#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll N;
  string S;
  cin >> N;
  cin >> S;
  vector<int> SwitchIdxes;
  // x or o しか含まれない個数を考える
  SwitchIdxes.push_back(-1);
  for (int i=0; i<N-1; i++) {
    // 切り替わりを求める
    if (S[i] != S[i+1]) {
      SwitchIdxes.push_back(i);
    }
  }
  SwitchIdxes.push_back(N-1);
  ll rest = 0ll;
  for (int i=1; i<SwitchIdxes.size(); i++) {
    ll cnt = SwitchIdxes[i] - SwitchIdxes[i-1];
    rest+=(cnt-1)*cnt/2;
  }
  ll ans = N*(N-1)/2 - rest;
  cout << ans << endl;
}
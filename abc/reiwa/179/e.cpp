#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
ll N, X, M;
unordered_map<ll, int> A; // index: あまり

int main() {
  INCANT;
  cin >> N >> X >> M;
  ll now = X;
  int idx=1;
  vector<ll> B;
  rep(i, min(N, M+1)) {
    if (A[now]>0) break;
    A[now] = idx; // 1-index
    B.push_back(now);
    now =(now*now)%M;
    idx++;
  }
  ll ret=0ll;
  if (B.size()==N) {
    for (int i=0; i<B.size(); i++) ret+=B[i];
    cout << ret << endl;
    return 0;
  }
  rep(i, A[now]-1) {
    ret+=B[i];
  }
  N-=(A[now]-1);
  ll circle_num = idx-A[now];
  ll circle_value = 0;
  for (int i=A[now]-1; i<idx-1; i++) {
    circle_value+=B[i];
  }
  ret+=circle_value*(N/circle_num);
  N%=circle_num;
  for (int i=A[now]-1; i< A[now]+N-1; i++) {
    ret+=B[i];
  }
  cout << ret << endl;
  return 0;
}
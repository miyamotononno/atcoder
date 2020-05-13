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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
int N;
int D[100005];
vector<int> S;

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> D[i];
  if (D[0]^D[N-1]) S.push_back(0);
  rep(i, N-1) {
    if (D[i]^D[i+1]) S.push_back(i+1);
  }
  if (S.size()==0) {
    cout << -1 << endl;
    return 0;
  }
  int MAX=0;
  rep(i, S.size()-1) {
    MAX= max(MAX, (S[i+1]-S[i]-1)/2);
  }
  MAX=max(MAX, (S[0]+N-S[S.size()-1]-1)/2);
  cout << MAX + 1<< "\n";
  return 0;
}
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
int N;
string S;
map<char, int> M;


int main() {
  INCANT;
  cin >> N >> S;
  rep(i, N) M[S[i]]++;
  int res=0;
  for (auto p: M) {
    res+=p.second%2;
  }
  cout << res << "\n";
  return 0;
}
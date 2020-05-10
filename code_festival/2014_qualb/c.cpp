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
typedef long long ll;
using namespace std;
int N;
int S1[26], S2[26], S3[26];

void input(int S[26]) {
  string t;
  cin >> t;
  N = t.size()/2;
  rep(i, 2*N) S[t[i]-'A']++;
}

int main() {
  INCANT;
  input(S1);
  input(S2);
  input(S3);
  int MIN=0;
  int MAX=0;
  rep(i, 26) {
    MIN+=max(0,S3[i]-S2[i]);
    MAX+=min(S1[i], S3[i]);
  }

  string ans = N>=MIN && N<=MAX?"YES":"NO";
  cout << ans << "\n";
  return 0;
}
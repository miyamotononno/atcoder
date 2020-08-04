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
const int INF = 2e9;
string S;

bool check(int left, int right) {
  for (int i=left; i<=right; i++) {
    if (S[i]!=S[right-i]) {
      return false;
    }
  }
  return true;
}

string calc(int N) {
  if (!check(0, N-1)) return "No";
  if (!check(0, (N-1)/2-1)) return "No";
  if (!check((N+1)/2, N-1)) return "No";
  return "Yes";
}

int main() {
  INCANT;
  cin >> S;
  int N = S.size();
  cout << calc(N) << "\n";
  return 0;
}
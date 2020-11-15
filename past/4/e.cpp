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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
string S;

int main() {
  INCANT;
  cin >> N;
  cin >> S;
  int a[N];
  rep(i, N) a[i]=i;
  do {
    string tmp = "";
    for (int i = 0; i < N; i++) tmp+=S[a[i]];
    if (tmp==S) continue;
    bool revFlag = true;
    for (int i=N-1; i>=0; i--) {
      if (tmp[i]!=S[N-1-i]) {
        revFlag=false;
        break;
      }
    }
    if (revFlag) continue;
    cout << tmp << endl;
    return 0;
  } while(next_permutation(a, a + N));
  cout << "None" << endl;
  return 0;
}
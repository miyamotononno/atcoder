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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
int Cnt[26]; 
string S;

// 偶数n個,1の数k個

int main() {
  INCANT;
  cin >> S;
  int N = S.size();
  rep(i, N) Cnt[S[i]-'a']++;
  sort(Cnt, Cnt+26, greater<int>());
  int odd=0;
  
  rep(i, 26) {
    if (Cnt[i]==0) break;
    if (Cnt[i]%2==1) odd++;
  }
  if (odd==0 || odd==1) {
    cout << N << endl;
    return 0;
  }
  cout << (N-odd)/(2*odd)*2+1 << endl;

}
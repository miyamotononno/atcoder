#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <cmath>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, D, K;
int s[101], t[101];
int l[10001], r[10001];

int main() {
  INCANT;
  cin >> N >> D >> K;
  rep(i, D) cin >> l[i] >> r[i];
  rep(i, K) cin >> s[i] >> t[i];

  rep(i, K) {
    bool rev = t[i] < s[i]; 
    int now = s[i];
    int goal = t[i];
    if (rev) {
      rep(j, D) {
        if (now <= r[j] && now >= l[j]) {
          if (goal >= l[j]) {
            cout << j+1 << endl;
            break;
          }
          else now = l[j];
        }
      }
    } else {
      rep(j, D) {
        if (now >= l[j] && now <= r[j]) {
          if (goal <= r[j]) {
            cout << j+1 << endl;
            break;
          }
          else now = r[j];
        }
      }
    }
  }

  return 0;
}
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
int W,H,N;
bool A[101][101];

int main() {
  INCANT;
  cin >> W >> H >> N;
  int a,x,y;
  rep(i, N) {
    cin >> x >> y >> a;
    if (a==1) {
      rep(j, x) {
        rep(k, H) {
          A[k][j]=true;
        }
      }
    } else if (a==2) {
      rep(j, W-x) {
        rep(k, H) {
          A[k][j+x]=true;
        }
      }
    } else if (a==3) {
      rep(j, y) {
        rep(k, W) {
          A[j][k] = true;
        }
      }
    } else {
      rep(j, H-y) {
        rep(k, W) {
          A[j+y][k] = true;
        }
      }
    }
  }
  int cnt=0;
  rep(i, H) rep(j, W) cnt += !A[i][j];
  cout << cnt << "\n";
  return 0;
}
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
int N, Q, M;
int Query[100005][3];
bool score[100005][51];
int point[51];
// g++ a.cpp -std=gnu++17

int main() {
  INCANT;
  cin >> N >> M >> Q;
  int a,b,c;
  rep(i, Q) {
    cin >> Query[i][0];
    if (Query[i][0]==1) {
      cin >> Query[i][1];
      Query[i][1]--;
    } else {
      cin >> Query[i][1];
      Query[i][1]--;
      cin >> Query[i][2];
      Query[i][2]--;
    }
  }
  fill(point, point+M, N);
  rep(i, Q) {
    if (Query[i][0]==1) {
      int ret =0;
      rep(j, M) {
        if (score[Query[i][1]][j]) {
          ret+=point[j];
        }        
      }
      cout << ret << endl;
    } else {
      score[Query[i][1]][Query[i][2]]=true;
      point[Query[i][2]]--;
    }
  }
  return 0;
}
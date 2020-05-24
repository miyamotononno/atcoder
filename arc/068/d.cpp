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
map<int, int> M;
priority_queue<int> que;
int D[2];

int main() {
  INCANT;
  cin >> N;
  int a;
  rep(i, N) {
    cin >> a;
    M[a-1]++; 
  }
  for (auto p: M) {
    int cnt = p.second;
    while(cnt>2) {
      cnt = cnt/3+cnt%3;
      M[p.first] = cnt;
    }
    D[cnt-1]++;
  }
  int SUM = D[0]+D[1];
  SUM-=D[1]%2;
  cout << SUM << "\n";
  return 0;
}
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
int N,K;

int win(int me) {
  int i=0;
  while(me<K) {
    me*=2;
    i++;
  }
  return i;
}

double probability(int i) {
  return pow(0.5,i);
}
 
int main() {
  INCANT;
  cin >> N >> K;
  if (K==1) {
    cout << 1 << endl;
    return 0;
  }
  double SUM=0;
  rep(i, N) {
    SUM+=probability(win(i+1));
  }
  SUM/=N;
  cout << SUM << "\n";
  return 0;
}
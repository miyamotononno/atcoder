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
int K, T;
priority_queue<int> que;

int main() {
  INCANT;
  cin >> K >> T;
  int a;
  rep(i, T) {
    cin >> a;
    que.push(a);
  }
  
  while(que.size()>1) {
    int b =que.top(); que.pop();
    int c = que.top(); que.pop();
    if (b-1!=0) que.push(b-1);
    if (c-1!=0) que.push(c-1);
  }
  cout << que.top()-1 << endl;
  return 0;
}
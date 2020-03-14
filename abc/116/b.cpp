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
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int s;
vector<int> a;
map<int, int> M; 

void calc(int idx) {
  if (a[idx-1]%2==0) a.push_back(a[idx-1]/2);
  else a.push_back(a[idx-1]*3+1);
} 

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  a.push_back(s);
  M[s] = 1;
  int idx = 1;
  while(true) {
    calc(idx);
    if (M[a[a.size()-1]]>0) {
      cout << a.size() << "\n";
      return 0;
    }
    M[a[idx]] = idx;
    idx++;
  }
  
  return 0;
}
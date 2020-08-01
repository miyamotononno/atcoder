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
ll N;

vector<char> calc(ll N) {
  vector<char> ret;
  while(N>0) {
    ll i = N%26ll;
    if (i==0) {
      ret.push_back('z');
      N-=26;
    }
    else {
      char c = i+'`';
      ret.push_back(c);
    }  
    N/=26;
  }
  return ret;
}

int main() {
  INCANT;
  cin >> N;
  vector<char> vec = calc(N);
  for (int i=vec.size()-1; i>=0; i--) {
    cout << vec[i];
  }
  cout << "\n";
  return 0;
}
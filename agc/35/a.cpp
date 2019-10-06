#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
map<int, int> Mp; // unordered_mapとは異なり、昇順で保存される。

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int a;
  vector<int> vec;
  rep(i, N){
    cin >> a;
    if (Mp[a]==0) vec.push_back(a);
    Mp[a] += 1;
  }
  if (vec.size() > 3) {
    cout << "No" << "\n";
    return 0;
  }
  if (vec.size() == 1){
    if (vec[0]==0) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;
  }

  if (N%3!=0) {
    cout << "No" << "\n";
    return 0;
  }

  if (vec.size() == 2){
    int a = vec[0];
    int b = vec[1];
    if (a!=0 && b!=0){
      cout << "No" << "\n";
      return 0;
    }
    if (Mp[0]==N/3) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;
  }

  for (auto it=Mp.begin(); it !=Mp.end(); ++it){
    int cnt = it->second;
    if (cnt != N/3){
      cout << "No" << "\n";
      return 0;
    }
  }

  if ((vec[0] ^ vec[1] ^ vec[2])==0) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
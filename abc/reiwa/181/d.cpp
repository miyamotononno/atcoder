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
string S;
int A[4]; // 2で割れない、4で割れない、8で割れない、8

int main() {
  INCANT;
  cin >> S;
  int n = S.size();
  for (auto c: S) {
    int a = c-'0';
    if (a%8==0) A[3]++;
    else if (a%4==0) A[2]++;
    else if (a%2==0) A[1]++;
    else A[0]++;
  }
  if (A[0] == n) {
    cout << "No" << "\n";
    return 0;
  }
  if (n==1) {
    if (A[3]==1) cout << "Yes" << endl;
    else cout << "No" << "\n";
    return 0;
  }
  if (n==2) {
    if (A[3]>=2 || (A[0]>=1 && A[1]>=1) || (A[1]>=1 && A[2]>=1) || (A[2]>=1 && A[3]>=1)) {
      cout << "Yes" << endl;
    } else cout << "No" << "\n";
    return 0; 
  }
  if (A[0]==0) {
    if (A[3]>=2 || (A[1]>=1 && A[2]>=1) || (A[2]>=1 && A[3]>=1)) {
      cout << "Yes" << endl;
    } else cout << "No" << "\n";
    return 0;
  }
  
  A[0]--;
  // 3けた目が奇数
  if ((A[0]>0 && A[1]>0) || (A[1]>0 && A[3]>0) || (A[2]>1) || (A[3]>0 && A[2]>0)) { //12, 28, 44, 84
    cout << "Yes" << endl;
    return 0;
  }
  // 3けた目が偶数
  rep(i, 3) {
    if (A[i+1]==0) continue;
    A[i+1]--;
    if (A[3]>=2 || (A[0]>=1 && A[1]>=1) || (A[1]>=1 && A[2]>=1) || (A[2]>=1 && A[3]>=1)) {
      cout << "Yes" << endl;
      return 0;
    } 
  }
  cout << "No" << "\n";
  return 0;
}
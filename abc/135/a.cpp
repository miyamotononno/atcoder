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
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
int A, B;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B;
  if ((A-B)%2){
    cout << "IMPOSSIBLE"<< endl;  
    return 0;  
  }
  if (A > B){
    cout << B + (A-B)/2 << endl;
  }else{
    cout << A + (B-A)/2 << endl;
  }
  return 0;
}
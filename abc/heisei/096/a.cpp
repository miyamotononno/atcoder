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
int a, b;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    if (a==1) {
      cout << 1 << endl;
      return 0;
    }
    if (a>b){
      cout << a-1 << endl;
    }else{
      cout << a << endl;
    }

    return 0;
}
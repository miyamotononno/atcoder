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
using namespace std;
typedef long long ll;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll X, Y;
    cin >> X >> Y;
    int cnt = 0;
    while(X<=Y){
        cnt++;
        X*=2;
    }
    cout << cnt << endl;
    return 0;
}
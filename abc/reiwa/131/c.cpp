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
ll A, B, C, D;

ll calc(ll n, ll x){
    ll a = n /C;
    ll b = n /D;
    ll c = n/x; 
    return n - (a+b-c);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B >> C >> D;
    ll tmp1 = C;
    ll tmp2 = D;
    ll r = tmp2 % tmp1;
    while(r!=0){
    tmp2 = tmp1;
    tmp1 = r;
    r = tmp2 % tmp1;
    }
    
    ll x = (C*D) / tmp1;
    ll ans = calc(B, x) - calc(A-1, x);
    cout << ans << endl;
    return 0;
}
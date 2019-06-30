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
int N, K;
ll V[2005][2005];

void comb(){
    rep(i, N+1){
        V[i][0]=1;
        V[i][i]=1;
        rep(j,i){
            ll a=(V[i-1][j-1]+V[i-1][j]);
            V[i][j]=a%MOD;
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    comb();
    rep(i,K) cout << (V[N-K+1][i+1]*V[K-1][i])%MOD << endl;
    return 0;
}
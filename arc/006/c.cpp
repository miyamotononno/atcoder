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
int N;
int W[50];
int towers[50];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    rep(i,N) cin >> W[i];
    towers[0] = W[0];
    int cnt = 1;
    if (N==1){
        cout << cnt << endl;
        return 0;
    }
    for(int i=1; i<N; i++){
        bool flag = true;
        for(int j=0; j<cnt; j++){
            if (towers[j] >= W[i]){
                towers[j] = W[i];
                flag = false;
                break;
            }
        }
        if(flag){
            towers[cnt] = W[i];
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
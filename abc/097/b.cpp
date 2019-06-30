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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int X;
    cin >> X;
    if (X<4){
        cout << 1 << endl;
        return 0;
    }

    int ans = 0;
    for(int i=2; i<= X;i++){
        int p=2;
        int b = pow(i,p);
        if(b>X){
            break;
        }
        while(b<=X){
            p++;
            if(pow(i,p)>X) break;
            b=pow(i,p);
        }
        ans = max(ans, b);
    }

    cout << ans << endl;
    return 0;
}

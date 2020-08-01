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
int N,W;
int v[205], w[205];
int DP2[201][2001],DP3[201][2001];
int v_sum, w_sum;

int solve1(){
    //価値が全て2000以下
    //DP1[idx]に格納するのはそのvalueを達成するための重さの最小値
    vector<int> DP1(v_sum+1, W+1);
    int ans=v_sum+1;
    rep(i, v_sum+1){ 
        if(i==0) continue;
        int min_w = W+1;
        rep(j, N){
            if (i - v[i]<0){
                min_w = w[i]
            }else{
                
            }
            int a = min(DP1[i - v[i]] + w[i], DP1[i]);
            min_w = min(min_w, a);
        }
        DP1[i] = min_w;
    }

    rep(i, v_sum+1) cout << DP1[i] << endl;

    return ans;
}

int solve2(int idx, int weight){
    //重さが全て2000以下
    //DP1[idx][w]に格納するのはその重さで達成されるvalueの最小値
    if (idx<0) return 0;
    if (DP2[idx][weight]) return DP2[idx][weight];

    int dfs1 = solve2(idx-1, weight);
    if(weight-w[idx]<0){
        DP2[idx][weight] = dfs1;
        return dfs1;
    }

    int dfs2 = solve2(idx-1, weight-w[idx]) + v[idx];
    int ans = max(dfs1, dfs2);
    DP2[idx][weight] = ans;
    return ans;
}

int solve3(){
    return 1;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> W;
    bool flag1=true; 
    bool flag2=true;
    rep(i,N){
        int a,b;
        cin >> a >> b;
        if (a>1000) flag1=false;
        if (b>1000) flag2=false;
        v_sum+= a;
        w_sum+= b;
        v[i] = a;
        w[i] = b;
    } 
    int ans;
    if(flag1){
        cout << 'a' << endl;
        ans = solve1();
    } 
    else if(flag2){
        cout << 'b' << endl;
        ans = solve2(N, W);
    }else{
        cout << 'c' << endl;
        ans = solve3();
    }
    
    cout << ans << endl;

    return 0;
}
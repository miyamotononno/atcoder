#include <algorithm>
#include <iostream>
#include <cstring>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
#define rep(i,n) for (int i=0; i<n;++i)
using namespace std;
const int MOD=1e9+7;
int D; 
int dp[100001][2][100];
string N;
 
int main(){
    cin>>D>>N;
    int l=N.size();
    dp[0][0][0]=1;
    rep(i,l){ // 長さ
        int A=N[i]-'0';
        rep(j,2){ //制約のあるなし 1だと制限なし
            rep(k,D){ // あまりの個数
                rep(a,j?9:A){ //その桁の最大の数
                    bool flag = j||a<A;
                    int next_a = (k+a)%D;
                    dp[i+1][flag][next_a]+=dp[i][j][k];
                    dp[i+1][flag][next_a]%=MOD;
                }
            }
        }
    }
    cout<<((dp[l][0][0]+dp[l][1][0])%MOD+MOD-1)%MOD<<endl;
    return 0;
}
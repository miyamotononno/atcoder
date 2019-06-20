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
int T,N,M;
int A[100];
int B[100];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T >> N;
    rep(i,N) cin >> A[i];
    cin >> M;
    rep(i,M) cin >> B[i];

    if (N < M){
        cout << "no" << "\n";
        return 0;
    }

    queue<int> que;
    int a_idx = 0;
    for(int i=0; i<M; i++){
        bool flag = true;
        if (a_idx < N & A[a_idx] <= B[i]){
            que.push(A[a_idx]);
            a_idx++;
        }  
        while(!que.empty()){
            int a = que.front();
            int cnt=0;
            for (int j=a_idx;j<N; j++){
                if (A[j] <= min(B[i], a+T)){
                    que.push(A[j]);
                    cnt++;
                }
            }
            a_idx+=cnt;
            if (a_idx < N & A[a_idx] < B[i]){
                que.push(A[a_idx]);
                a_idx++;
                flag=false;
            }
            que.pop();
            if(a+T < B[i]) continue;
            else{
                flag=false;
                break;
            }
        }
        if(flag){
            cout << "no" << "\n";
            return 0;
        }
    }

    cout << "yes" << "\n";
    return 0;
}
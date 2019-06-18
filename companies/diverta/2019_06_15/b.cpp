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
int N;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<pair<int, int> > balls(N);
    rep(i,N) cin >> balls[i].first >> balls[i].second;
    sort(balls.begin(), balls.end());
    int cnt = 0;
    rep(i,N){
        for(int j=i+1; j<N; j++){
            int tmp = 1; //iとjを通る分に関してはここでカウントする。
            int x = balls[j].first-balls[i].first;
            int y = balls[j].second-balls[i].second;
            for(int k=i; k<N; k++){ 
                for(int l=k+1; l<N;l++){
                    if (i == k & j==l) continue; 
                    if (balls[l].second-balls[k].second == y & balls[l].first-balls[k].first == x) tmp+=1;
                }
            }
            cnt = max(cnt, tmp);
        }
    }

    cout << N - cnt << endl;
    return 0;
}

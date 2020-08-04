#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int INF = 1000000007;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, C;
    cin >> N >> C;
    int D[C][C];
    int color[N][N];
    for (int i=0; i<C; i++)
        for (int j=0; j<C; j++) cin >> D[i][j];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) cin >> color[i][j], --color[i][j];

    vector<vector<int> > cost(3, vector<int>(C, 0));
    for (int c=0; c<C; c++){
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                int t = (i+j)%3;
                cost[t][c] += D[color[i][j]][c];
            }
        }
    }
        
    int ans = INF;
    int c[3];
    for (c[0] = 0; c[0]<C; ++c[0]){
        for (c[1] = 0; c[1]<C; ++c[1]){
            if (c[0] == c[1]) continue;
            for (c[2] = 0; c[2]<C; ++c[2]){
                if (c[0]==c[2] || c[1]==c[2]) continue;
                int tmp = 0;
                for (int i=0; i<3; i++) tmp += cost[i][c[i]];
                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

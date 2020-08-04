#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#define rep(i,n) for (int i=0; i<n;++i)
using namespace std;
queue<int> Ready, Next;
int N;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<vector<int> > A(N, vector<int>(N-1));
    int a;
    rep(i, N){
      rep(j, N-1){
        cin >> a;
        a--;
        A[i][j] = a;
      }
      Ready.push(i);
    }

    int ans = 0;
    vector<int> Idx(N, 0); //N人の試合の進み具合
    vector<vector<bool> > Finished(N, vector<bool>(N));
    rep(i, N) Finished[i][0] = true;
    while(!Ready.empty()){
      cout << ans+1 << "日目" << "\n";
      while(!Ready.empty()){
        int player = Ready.front();
        Ready.pop();
        int now_game = Idx[player];
        int other = A[player][now_game];

        // その日は試合できず
        if (A[other][Idx[other]]!=player) continue;

        // 試合成立
        cout << player+1 << "と" << other+1 << "\n";
        Idx[player]++;
        Idx[other]++;
        Finished[player][now_game] = true;
        Finished[other][Idx[other]] = true;
        if (Idx[player]<N) Next.push(player);
        if (Idx[other]<N) Next.push(other);
      }
      ans++;

      while(!Next.empty()){
        int p = Next.front();
        Ready.push(p);
        Next.pop();
      }
    }

    bool ok = true;
    rep(i, N){
      if (Idx[i]==N) ok = false; 
    }

    cout << (ok ? ans : -1) << "\n";
    return 0;
}

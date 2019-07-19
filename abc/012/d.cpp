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
#include <limits>
#define rep(i,n) for (int i=0; i<n;++i)
using namespace std;
const int INF = 100000000;
int N, M;
int d[303][303];

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int a, b, t;
    Fill(d, INF);
    rep(i, M){
      cin >> a >> b >> t;
      a--, b--;
      d[a][b] = t, d[b][a] = t;
    }
    rep(k, N){
      rep(i, N){
        rep(j, N) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }

    int min_d = INF;
    rep(i, N){
      int max_d = 0;
      rep(j, N){
        if (i==j) continue;
        max_d = max(d[i][j], max_d);
      }
      min_d = min(min_d, max_d);
    }

    cout << min_d << endl;
    
    return 0;
}
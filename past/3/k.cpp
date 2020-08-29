using namespace std;
#include <iostream>
#define rep(i,n) for (int i=0; i<n;++i)

int N, Q;
int container[200005]; // i番目のコンテナの下のコンテナのindex
int desk[200005]; // 最上位にあるコンテナのindex
int ans[200005];

void init() {
  rep(i, N) {
    container[i] = -1;
    desk[i] = i;
  }
}

void dfs(int cont, int& desk_key) {
  ans[cont] = desk_key;
  if (container[cont] ==-1) return;
  dfs(container[cont], desk_key); 
}

int main() {
  cin >> N >> Q;
  init();
  int f,t,x;
  rep(i, Q) {
    cin >> f >> t >> x;
    f--;t--;x--;
    int tep = desk[f];
    desk[f] = container[x];
    container[x] = desk[t];
    desk[t] = tep;
  }

  rep(i, N) {
    if (desk[i]==-1) continue;
    dfs(desk[i], i);
  }

  rep(i, N) {
    cout << ans[i]+1 << endl;
  }
}
using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#define rep(i,n) for (int i=0; i<n;++i)
int N,K;
vector<int> kouho;
queue<int> que;

int bfs() {
  int k = que.front(); que.pop();
  while(k<N) {
    for(auto p: kouho) que.push(k*10+p);
    k = que.front(); que.pop();
  }
  return k;
}
bool D[10];
int main() {
  cin >> N >> K;
  int d;
  rep(i, K) {
    cin >> d;
    D[d] = true;
  }
  
  rep(i, 10) {
    if (!D[i]) {
      kouho.push_back(i);
      if (i>0) que.push(i);
    }
  }
  cout << bfs() << endl;
}

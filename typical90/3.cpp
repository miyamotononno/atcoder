#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> P;

vector<int> T[100005];
int n;
const int INF = 2e9;

// 木の直径 + 1

// startから最も遠いNodeを取得
P getLongestNode(int s) {
  queue<int> que;
  que.push(s);
  vector<int> Cost(n);
  generate(Cost.begin(), Cost.end(), [](){return INF;});
  Cost[s] = 0;
  int node;
  while(!que.empty()) {
    int n = que.front(); que.pop();
    node = n;
    for (auto c: T[n]) {
      if (Cost[c]>Cost[n]+1) {
        Cost[c] = Cost[n]+1;
        que.push(c);
      }
    }
  }
  return P(node, Cost[node]);
}

int main() {
  
  cin >> n;
  int a,b;
  for (int i=0; i<n-1; i++) {
    cin >> a >> b;
    a--;b--;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  P p = getLongestNode(0);
  P q = getLongestNode(p.first);
  cout << q.second +1 << endl;
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n;
vector<int> G[100005];
int record[100005]; // 0,1,2

void dfs(int s, int d) {
  if (record[s]>0) return;
  record[s] = d;
  for (int node: G[s]) {
    if (record[node]>0) continue;
    if (d==1) {
      dfs(node, 2);
    } else {
      dfs(node, 1);
    }
  }
}

int main() {
  cin >> n;
  int a,b;
  for (int i=0; i<n-1; i++) {
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a); 
  }
  dfs(0, 1);
  int cnt1 = 0;
  for (int i=0; i<n; i++) {
    if (record[i]==1) cnt1++; 
  }
  int cnt = 0;
  if (cnt1 >= (n/2)) {
    for (int i=0; i<n; i++) {
      if (cnt==(n/2)) {
        cout << endl;
        return 0;
      }
      if (record[i]==1) {
        cout << i+1 << ' ';
        cnt++;
      }
    }
  } else {
    for (int i=0; i<n; i++) {
      if (cnt==(n/2)) {
        cout << endl;
        return 0;
      }
      if (record[i]==2) {
        cout << i+1 << endl;
        cnt++;
      }
    }
  }
}
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <stack>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
int c[13];
vector<int> V;

int calc_MIN(int b){ // 0 <=  b < 1<<24
  int MIN=12;
  int prev = -1;
  bool flag = false;
  rep(i, 25)  {
    if (i==0) continue;
    int mask = 1<<i;
    if (b & mask) {
      if (!flag) MIN = i;
      else MIN = min(MIN, i-prev);
      prev = i;
      flag = true;
    }
  }
  return MIN;
}

void create_vec(int idx, stack<int> st) {
  if (idx==13) {
    int d=1;
    while(!st.empty()) {
      int q = st.top();st.pop();
      d+=(1<<q);
    }
    d+=(1<<24);
    V.push_back(d);
    return;
  }
  if (c[idx]==1) {
    st.push(idx);
    create_vec(idx+1, st);
    st.pop();
    if (idx < 12) {
      st.push(24-idx);
      create_vec(idx+1, st);
    }
  } else if (c[idx]==2) { // 同じものに関しては最終的に0になり、候補外 
    st.push(idx);
    st.push(24-idx);
    create_vec(idx+1, st);
  }
  else create_vec(idx+1, st);
}

int main() {
  INCANT;
  cin >> N;
  int d;
  rep(i, N) {
    cin >> d;
    c[min(24-d, d)]++;
  }
  c[0]++; // 高橋
  if (c[0]>1 || c[12]>1) {
    cout << 0 << endl;
    return 0;
  }
  rep(i,13) {
    if (c[i]>2) {
      cout << 0 << endl;
      return 0;
    }
  }
  stack<int> st;
  create_vec(1, st);
  int MAX=0;
  rep(i, V.size()) MAX  = max(MAX, calc_MIN(V[i]));
  cout << MAX << endl;
  
  return 0;
}

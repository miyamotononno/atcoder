#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <stack>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, M, Q;
vector<vector<int> > A;
int Ques[51][4];

void dfs(int idx, int pre, stack<int> st) {
  if (idx==N) {
    vector<int> v;
    rep(i, N) {
      v.push_back(st.top());
      st.pop();
    }
    A.push_back(v);
    return;
  }

  for (int i=pre; i<=M; i++) {
    st.push(i);
    dfs(idx+1, i, st);
    st.pop();
  }
} 

int main() {
  INCANT;
  cin >> N >> M >> Q;
  int a,b,c,d;
  rep(i, Q) {
    cin >> a >> b >> c >> d;
    a--;b--;
    Ques[i][0]=a;
    Ques[i][1]=b;
    Ques[i][2]=c;
    Ques[i][3]=d;
  }
  stack<int> st = {};
  dfs(0,1,st);
  int ans=0;
  for (auto vec: A) {
    assert(vec.size()==N);
    int tmp=0;
    rep(i, Q) {
      int a = Ques[i][0],b=Ques[i][1];
      if (vec[N-b-1]-vec[N-1-a]==Ques[i][2]) tmp+=Ques[i][3];
    }
    ans =max(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
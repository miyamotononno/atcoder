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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
int N;
typedef pair<int, int> P;
vector<P> X;
vector<P> Y;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int a;
  rep(i, N){
    cin >> a;
    P p = make_pair(a, i);
    X.push_back(p);
  }
  sort(X.begin(), X.end());

  int s_medi = X[N/2-1].first;
  int b_medi = X[N/2].first;

  rep(i, N){
    if(i<N/2){
      P p = make_pair(X[i].second, b_medi);
      Y.push_back(p);
    } else{
      P p = make_pair(X[i].second, s_medi);
      Y.push_back(p);
    }
  }

  sort(Y.begin(), Y.end());
  rep(i, N){
    cout << Y[i].second << endl;
  }

  return 0;
}
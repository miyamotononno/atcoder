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
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int N;
typedef pair<ll, ll> P;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  P PP[101];
  P PN[101];
  P NP[101];
  P NN[101];
  ll a, b;
  rep(i, N){
    cin >> a >> b;
    P p = make_pair(a,b);
    if (a==0 && b==0) continue;
    if (a>=0&&b>=0){
      PP[i] = p;
    } else if (a>=0&&b<0){
      PN[i] = p;
    } else if (a<0&&b>=0){
      NP[i] = p;
    } else{
      NN[i] = p;
    }
  }

  
  cout << N << "\n";
  return 0;
}
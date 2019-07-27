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
int M,N;
int a[200004], ball[200004];

int main(){
  cin >> N;
  cin.ignore();
  rep(i, N) cin >> a[i];

  for (int i=N; i>0; --i){
    int ballcnt=0;
    for(int j=2*i; j<=N; j+=i) ballcnt += ball[j-1];
    if(ballcnt%2 != a[i-1]) ball[i-1] = 1;
  }

  rep(i, N) M+=ball[i];

  cout << M << endl;

  rep(i, N){
    if(!ball[i]) continue;
    cout << i+1 << " ";
  }
  return 0;
}
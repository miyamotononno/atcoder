#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <utility>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <functional>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
using namespace std;
int N;
int P[101];
vector<vector<int> > M;

// n番目（p[n-1]まで）でvを作れるか
bool canMake(int n, int v){
    if (M[n][v] != -1) return  M[n][v] == 1;
    if (n == 0) return v == 0;

    if (v < P[n-1]){
        if(canMake(n-1, v)){
            M[n][v] = 1;
            return true;
        }else{
            M[n][v] = 0;
            return false;
        }
    }else{
        if(canMake(n-1, v-P[n-1]) || canMake(n-1, v)){
            M[n][v] =1;
            return true;
        }else{
            M[n][v] = 0;
            return false;
        }
    }
}

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> N;
  int sum = 0;
  rep(i,N){
      cin >> P[i];
      sum+= P[i];
  }
  
  M = vector<vector<int> >(N+1, vector<int>(sum+1, -1));
  int ans = 0;
  rep(i,sum+1) if(canMake(N, i))ans++;
  
  cout << ans << endl;
  return 0;

}
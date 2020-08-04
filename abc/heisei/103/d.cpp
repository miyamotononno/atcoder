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
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
using namespace std;
int N, M;

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> N >> M;

  vector<pair<int, int> > conflicts(M);
  rep(i,M){
    cin >> conflicts[i].second >> conflicts[i].first;
  }

  sort(conflicts.begin(), conflicts.end());
  int ans = 0;
  int tmp_first,tmp_second; 
  rep(i, M){
    int i_cf = conflicts[i].first;
    int i_cs = conflicts[i].second;
    if(i==0){
        ans++;
        tmp_first = i_cf;
        tmp_second = i_cs;
        continue;
    }
    if (i_cf == tmp_first){
        if (tmp_second < i_cs) tmp_second = i_cs;
        continue;
    }
    if (i_cs < tmp_first) continue;
    ans++;
    tmp_first = i_cf;
    tmp_second = i_cs;
  }

  cout << ans << endl;
  
  return 0;
}

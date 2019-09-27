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
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int H, W;
unordered_map<char, int> Ump;


bool calc1(){ // H＊W%4==0
  for (auto it=Ump.begin(); it !=Ump.end(); ++it){
    int cnt = it->second;
    if (cnt%4==0) continue;
    else return false;
  }
  return true;
}

bool calc2(int cnt_2){ // H＊W%4!=0 && H＊W%2==0

  for (auto it=Ump.begin(); it !=Ump.end(); ++it){
    int cnt = it->second;
    if (cnt%4==0) continue;
    if (cnt%2==1) return false;
    cnt_2--;
    if (cnt_2 < 0) return false;
  }
  return true;
}

bool calc3(int cnt_2){ // H＊W%2!=0
  int cnt_1 = 1;
  for (auto it=Ump.begin(); it !=Ump.end(); ++it){
    int cnt = it->second;
    if (cnt%4==0) continue;
    if (cnt%2==1) cnt_1--;
    else cnt_2--;
    if (cnt_1 < 0 || cnt_2 < 0) return false;
  }
  return true;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> H >> W;
  char a;
  rep(i, H){
    rep(j, W){
      cin >> a;
      Ump[a]+=1;
    }
  }

  bool flag =  false;
  int cnt_2 = 0;
  if (H%2==0 && W%2==0){
    flag = calc1();
  } else if ((H*W)%2==0){
    if (W%2==1) cnt_2 = H/2;
    else cnt_2 = W/2;
    flag = calc2(cnt_2);
  } else {
    cnt_2 = (H-1)/2 + (W-1)/2;
    flag = calc3(cnt_2);
  }
  string ans = flag?"Yes":"No";
  cout << ans << "\n";
  return 0;
}
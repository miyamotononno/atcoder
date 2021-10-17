#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
int n, k;
int a[100002];

int main() {
  cin >> n >> k;
  for (int i=0; i<n; i++) cin >> a[i];
  unordered_map<int, int> U;
  int lef,rig;
  lef = rig = 0;
  int maxSize = 1;
  while(lef<n || rig<n) {
    if (rig==n || U.size()>k) {
      // lef-=1して収まるか?
      U[a[lef]]--;
      if (!U[a[lef]]) U.erase(a[lef]);
      lef++;
    }
    if (rig<n && U.size()<=k) {
      U[a[rig]]++;
      rig++;
    }
    if (U.size()<=k) {
      maxSize = max(maxSize, rig-lef); // [lef, rig-1]  
    }
  }
  cout << maxSize << endl;
}
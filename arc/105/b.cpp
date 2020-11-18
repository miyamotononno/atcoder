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
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int n;
const int INF = 2e9;
int A[100005];
unordered_map<int, bool> U;
priority_queue<int> que;

int main() {
  INCANT;
  cin >> n;
  int a;
  int minNum=INF;
  rep(i, n) {
    cin >> a;
    if (!U[a]) {
      if (a<minNum) {
        minNum = a;
      }
      que.push(a);
    }
    U[a]=true;
  }
  int maxNum = que.top();
  while(maxNum!=minNum) {
    while(maxNum==que.top()) que.pop();
    int newVal = maxNum-minNum;
    que.push(newVal);
    if (minNum>newVal) minNum=newVal;
    maxNum = que.top();
  }
  cout << maxNum << endl;
  return 0;
}
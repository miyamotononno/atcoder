using namespace std;
#include <iostream>
#define rep(i, n) for(int i=0;i<n;i++)
const int INF = 2e9;
const int MAX_N = 1 << 17;
int bit[MAX_N+1], n;

int sum(int i) {
  int s=0;
  while(s>0) {
    s+=bit[i];
    i-=i&-i; // 
  }
  return s;
}

void add(int i, int x) {
  while(i<=n) {
    bit[i]+=x;
    i+=i&-i;
  }
}


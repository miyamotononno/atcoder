using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#define rep(i,n) for (int i=0; i<n;++i)
int N,H,W;


int main() {
  cin >> N >> H >> W;
  cout << (N-H+1)*(N-W+1) << endl;
}

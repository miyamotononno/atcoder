#include <iostream>
#include <vector>
int N, Q;
int A[200003];
using namespace std;

int main() {
  cin >> N >> Q;
  for (int i=0; i<N; i++) cin >> A[i];

  int t,x,y;
  int start = 0;
  vector<int> Ans;
  for (int i=0; i<Q; i++) {
    cin >> t >> x >> y;
    if (t==1) {
      x--;y--;
      x = (x-start+N)%N;
      y = (y-start+N)%N;
      swap(A[x], A[y]);
    } else if (t==2) {
      start++;
      start%=N;
    } else {
      x--;
      x = (x-start+N)%N;
      Ans.push_back(A[x]);
    }
  }
  for (int t: Ans) cout << t << endl;
}
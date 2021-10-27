#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, K;
typedef long long ll;
typedef pair<ll, int> P;
ll C[200003], B[200004];
bool Flag[200003];
priority_queue<P> que;

int main() {
  cin >> N >> K;
  ll a, b;
  for (int i=0; i<N; i++) {
    cin >> a >> b;
    B[i] = b;
    C[i] = a - b;
    que.push(P(b, i)); // 1分目の点とその時のindex 
  }
  ll ret = 0ll;
  for (int i=0; i<K; i++) {
    P p = que.top(); que.pop();
    ret+=p.first;
    if (Flag[p.second]) continue;
    Flag[p.second] = true;
    que.push(P(C[p.second], p.second));
  }

  cout << ret << endl;

}
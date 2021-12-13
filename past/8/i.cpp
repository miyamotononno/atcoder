#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(const vector<ll>& A) {
  priority_queue<ll, vector<ll>, greater<ll>> evenPque;
  priority_queue<ll, vector<ll>, greater<ll>> oddPque;
  for (ll a: A) {
    if (a%2==0) evenPque.push(a);
    else oddPque.push(a);
  }
  while(!evenPque.empty()) {
    ll e = evenPque.top(); evenPque.pop();
    e /= 2ll;
    if (!oddPque.empty() && oddPque.top() < e) {
      ll o = oddPque.top(); oddPque.pop();
      o *= 3ll;
      oddPque.push(o);
    } else {
      e *= 3ll;
    }
    if (e%2==0) {
      evenPque.push(e);
    } else {
      oddPque.push(e);
    }
  }

  return oddPque.top();
}

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }

  cout << solve(A) << endl;
}
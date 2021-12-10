#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

/*
[(10, 15), (8, 9), (11, 12)]

(9, 8), (15, 10),...


*/
bool isDoubleBooking(const vector<P>& A) {
  set<P> S; // (end, begin)
  for (P p: A) {
    auto itr  = S.lower_bound(P(p.first+1, -1));
    int targetStart = itr -> second;
    if (itr != S.end() && p.second>targetStart) { // if end time of new schedule is 
      return true;
    }
    S.insert(P(p.second, p.first));
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  vector<P> A(N);
  int d,s,t;
  for (int i=0; i<N; i++) {
    cin >> d >> s >> t;
    A[i] = P(d*24+s, d*24+t);
  }

  if (isDoubleBooking(A)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
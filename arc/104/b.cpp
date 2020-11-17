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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n;
string S;
string S2;
int A[5005], C[5005], T[5005], G[5005];
int AT[5005], CG[5005];
unordered_map<int, set<int> > CntsAT, CntsCG;

int calc(int x) {
  return x*(x-1)/2; 
}

int main() {
  INCANT;
  cin >> n;
  cin >> S;
  rep (i, n) {
    
    A[i+1]=A[i];
    T[i+1]=T[i];
    C[i+1]=C[i];
    G[i+1]=G[i];
    
    switch (S[i]) {
      case 'A':
        A[i+1]++;
        break;
      case 'T':
        T[i+1]++;
        break;
      case 'C':
        C[i+1]++;
        break;
      case 'G':
        G[i+1]++;
        break;
      default:
        break;
    }
  }
  rep(i, n+1) {
    CntsAT[A[i]-T[i]].insert(i);
    CntsCG[C[i]-G[i]].insert(i);
  }
  int ret=0;
  for (auto tmp: CntsAT) {
    int key = tmp.first;
    set<int> values = tmp.second;
    if (values.size()<2) continue;
    int cnt=0;
    unordered_map<int, int> Ump;
    for (auto v: values) {
      cnt=0;
      for (auto v2: CntsCG) {
        if (CntsCG[v2.first].find(v) != CntsCG[v2.first].end()) {
          Ump[v2.first]++;
          break;
        }
      }
    }
    for(auto tmp2: Ump) ret+=calc(tmp2.second);
  }

  cout << ret << endl;
  return 0;
}
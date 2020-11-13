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
const ll INF = 2e18;
ll N, A, B, C, D;
// 最初D枚払い、1枚からスタート

ll dfs(ll curr, unordered_map<ll, ll>& Memo) {
  if (curr == 0ll) return 0ll;
  if (curr==1ll) return D;
  if (Memo[curr] > 0) return Memo[curr];
  ll ret = INF;
  if (ret/D>curr) ret = D*curr; // Dをずっと払い続ける

  if (curr%2>0) {
    ret = min(ret, dfs((curr+1)/2, Memo)+D+A);
    ret = min(ret, dfs((curr-1)/2, Memo)+D+A);
  } else ret = min(ret, dfs(curr/2, Memo)+A);

  ll amari = curr%3ll;
  if (amari>0) {
    ret = min(ret, dfs((curr+3-amari)/3, Memo)+D*(3-amari)+B);
    ret = min(ret, dfs((curr-amari)/3, Memo)+D*amari+B);
  } else ret = min(ret, dfs(curr/3, Memo)+B);

  amari = curr%5ll;
  if (amari>0) {
    ret = min(ret, dfs((curr+5-amari)/5, Memo)+D*(5-amari)+C);
    ret = min(ret, dfs((curr-amari)/5, Memo)+D*amari+C);
  } else ret = min(ret, dfs(curr/5, Memo)+C);

  Memo[curr] = ret;
  return ret;
}


ll calc() {
  unordered_map<ll, ll> Memo;
  return dfs(N, Memo);
}

int main() {
  INCANT;
  int T;
  cin >> T;
  rep(i, T) {
    cin >> N >> A >> B >> C >> D;
    cout << calc() << "\n";
  } 
  return 0;
}
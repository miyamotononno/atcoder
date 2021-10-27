#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
typedef long long ll;

int N;
ll K;
unordered_set<int> exists;
vector<int> records;

int calcSumNum(int d) {
  int ret = 0;
  while(d>0) {
    ret+=(d%10);
    d/=10;
  }
  return ret;
}

void calcNewCircle(const vector<int>& original, vector<int>* newVec, int& tarVal) {
  bool flag = false;
  for (int t: original) {
    if (flag || t == tarVal) {
      newVec->push_back(t);
      flag = true;
    }
  }
}

const int MOD = 1e5;

int main() {
  cin >> N >> K;
  int cur = N;
  // 高々1e5
  while(K>0 && exists.find(cur) == exists.end()) {
    exists.insert(cur);
    records.push_back(cur);
    K--;
    cur = (cur + calcSumNum(cur)) % MOD;
  }
  if (K==0) {
    cout << cur << endl;
    return 0;
  }
  K++;
  vector<int> circleVec;
  calcNewCircle(records, &circleVec, cur);
  ll sz = circleVec.size();
  K %= sz;
  // K==1の時最初、K==0の時最後になることに注意
  cout << circleVec[(K+sz-1)%sz] << endl;
}


/*
MOD10と仮定
4 -> 8 -> 6(8+8->16->6) -> 2 (-> 4)
*/
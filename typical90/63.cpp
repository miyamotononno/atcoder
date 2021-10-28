#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;

int H, W;
int P[9][100001];

/*
all_of: https://cpprefjp.github.io/reference/algorithm/all_of.html
ラムダ式: https://cpprefjp.github.io/lang/cpp11/lambda_expressions.html
*/

int main() {
  cin >> H >> W;
  for(int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> P[i][j];
    }
  }
  int maxGrid = 0;
  for (int i=1; i<(1<<H); i++) {
    vector<int> choiced;
    for (int bit=0; bit<H; bit++) {
      if ((1<<bit) & i) {
        choiced.push_back(bit);
      }
    }
    int sz = choiced.size();
    unordered_map<int, int> U;
    for (int j=0; j<W; j++) {
      int cur = -1;
      int cnt = 0;
      vector<int> choicedVal;
      for (int k: choiced) {
        choicedVal.push_back(P[k][j]);
      }
      bool isAllSame = all_of(choicedVal.begin(), choicedVal.end(), [&](int x) {return x == P[choiced[0]][j];});
      if (isAllSame) {
        U[P[choiced[0]][j]]++;
      }
    }
    int colSize = 0;
    for (auto p: U) colSize = max(colSize, p.second);
    maxGrid = max(maxGrid, colSize*sz); 
  }
  cout << maxGrid << endl;
}
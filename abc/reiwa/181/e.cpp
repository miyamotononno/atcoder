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
int n,m;
int H[200003], W[200003];
int studentDiff[200003];
int oddStudentDiff[200003]; // 偶数indexは0
int evenStudentDiff[200003]; // 奇数indexは0
int sumOddStudentDiff[200003]; // 累積和
int sumEvenStudentDiff[200003]; // 累積和

int main() {
  INCANT;
  cin >> n >> m;
  rep(i, n) cin >> H[i];
  rep(i, m) cin >> W[i];
  sort(H, H+n);
  rep(i, n-1) {
    studentDiff[i]=H[i+1]-H[i];
    if (i%2==0) evenStudentDiff[i] = studentDiff[i];
    else oddStudentDiff[i] = studentDiff[i];
  }
  for (int i=0; i<=n-1; i++) {
    if (i%2==0) {
      if (i==0) {
        sumEvenStudentDiff[i] = evenStudentDiff[i];
        continue;
      }
      sumEvenStudentDiff[i] += sumEvenStudentDiff[i-1]+evenStudentDiff[i];
      sumOddStudentDiff[i] = sumOddStudentDiff[i-1];
    } else {
      sumOddStudentDiff[i] += sumOddStudentDiff[i-1]+oddStudentDiff[i];
      sumEvenStudentDiff[i] = sumEvenStudentDiff[i-1];
    }
  }
  int ans = 2e9;
  rep(i, m) {
    int tmp =0;
    int idx = lower_bound(H, H + n, W[i]) - H; // 1以上n以下
    if (idx==0) { // 全てW[i]よりも大きい
      tmp = H[0]-W[i];
      tmp += sumOddStudentDiff[n-1];
      ans = min(ans, tmp);
      continue;
    }
    if (idx==n) { // 全てW[i]以下
      tmp = W[i] - H[n-1];
      tmp += sumEvenStudentDiff[n-1];
      ans = min(ans, tmp);
      continue;
    }
    // 途中までeven, それからodd
    if (idx%2!=0) tmp = W[i]-H[idx-1];
    else tmp = H[idx] - W[i];
    tmp += sumEvenStudentDiff[idx-2];
    tmp += sumOddStudentDiff[n-1]-sumOddStudentDiff[idx-1];
    ans = min(ans, tmp);
  }
  cout << ans << "\n";
  return 0;
}
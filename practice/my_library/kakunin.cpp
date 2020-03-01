#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <cassert>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_itr(it, M) for (auto it = M.begin(); it != M.end(); ++it)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;

void trigonometric(double x) {
  cout << "三角関数：上からサインコサインタンジェント" << "\n";
  cout << sin(x / 180.0 * PI) << "\n";
  cout << cos(x / 180.0 * PI) << "\n";
  cout << tan(x / 180.0 * PI) << "\n";
}

void handle_string(string S) {
  string T = "abc";
  char c = 'd';
  cout << S+T << "\n";
  cout << S+c << "\n";
  cout << S.substr(1) << "\n";
  cout << S.substr(4, 100) << "\n"; // 超えても問題ない
}

void min_max() {
  cout << max({103, 168, 103}) << endl; 
  int c[3];
  c[0] = 29; c[1] = 23; c[2] = 32;
  // *min_element(c + l, c + r)は{c[l], c[l+1], ..., c[r-1]} の中で最小のものを返す。
  // iteraterを返すため、最初に*をつけること。max_elementも同様
  cout << *min_element(c, c + 3) << endl;
}

void reverseFunc() { // 計算量はO(n)
  int c[6] = {29, 23, 32, 25, 34, 73};
  reverse(c, c+6);
  reverse(c+1, c+3); // c[1]からc[2]まで逆順に入れ替える
  string S = "abcd";
  reverse(ALL(S));
  cout << S << "\n";
}

void sortFunc() {
  int a[8] = {8, 3, 7, 1, 4, 6, 2, 5};
  sort(a + 2, a + 6, greater<int>()); // 3-5番目の数字を降順に入れ替える
  rep(i, 8) cout << a[i];
  cout << "\n";
  vector<int> b = {8, 3, 7, 1, 4, 6, 2, 5};
  sort(b.begin()+2, b.begin()+6, greater<int>());
  rep(i, 8) cout << b[i];
  cout << "\n";
}

void mapFunc() {
  map <string, int> M;
  M["abc"] = 12;
  M["dfe"] = 24;
  M["def"] = 36;
  // 計算量はO(log(N))
  cout << M["abc"] << "\n";
  cout << M["xyz"] << "\n"; // 0

  for (auto it = M.begin(); it != M.end(); ++it){
    cout << it->first << "\t" << it->second << endl;
  }
  /*
  上記は以下のように辞書順で表示される(mapはキーの順序を保持しているため)
  abc     12
  def     24
  dfe     36
  xyz     0
  */
}

void xxx_bound() {
  int c[8] = {29, 23, 32, 30, 25, 34, 73, 30};
  vector<int> b = {29, 23, 32, 30, 25, 34, 73, 30};
  sort(c, c+8); // 23, 25, 29, 30, 30, 32, 34, 73 
  sort(ALL(b)); // 23, 25, 29, 30, 30, 32, 34, 73 
  // lower_bound(a+l, a+r, x) - aは、aの中でl+1番目からr-1番目で初めてx以上である最小のindexを返す
  cout << lower_bound(c, c + 8, 30) - c << endl;
  cout << lower_bound(ALL(b), 30) - b.begin() << endl;
  // upper_bound(a+l, a+r, x) - aは、aの中でl+1番目からr-1番目でxより大きい値が現れる最初のindexを返す
  cout << upper_bound(c, c + 8, 30) - c << endl;
  cout << upper_bound(ALL(b), 30) - b.begin() << endl;
}

void xxxset() {
  set<int> s; multiset<int> ms;
  s.insert(1); s.insert(1); s.insert(2);
  ms.insert(1); ms.insert(1); ms.insert(2);
  ms.erase(1); // 全て消すことに注意
  // rep_itr(itr, s) {
  //   cout << (*itr) << endl;
  // }
  ms.insert(3); ms.insert(4); ms.insert(5);
  cout << *ms.lower_bound(4) - *ms.begin() << endl; // 2,3,4,5
  cout << *lower_bound(ALL(ms), 4) - *ms.begin() << endl;
}

void assertion() {
  int N = 10;
  // #include <cassert>が必要
  assert(N<=1); // 条件に満たさないとエラーを吐く
  cout << "OK" << endl;
}

void count() {
  int c[8] = {29, 23, 32, 30, 25, 34, 73, 30};
  vector<int> b = {29, 23, 32, 30, 25, 34, 73, 30};
  cout << count(c, c + 8, 30) << endl;
  cout << count(ALL(b), 30) << endl;
}

void find() {
  int c[8] = {29, 23, 32, 30, 25, 34, 73, 30};
  vector<int> b = {29, 23, 32, 30, 25, 34, 73, 30};
  cout << find(c, c + 8, 100) - c << endl; // 要素がない場合は配列の長さ(ここでは8)。
  cout << find(ALL(b), 30) - b.begin()<< endl; // 要素がない場合はfindはc.end()と同じ
}

void next_permutaion_func() {
  int a[3] = {2,3,1};
  do {
    for (int i = 0; i < 3; i++) {
        if (i) cout << ",";
        cout << a[i];
    }
    cout << endl;
} while(next_permutation(a, a + 3));
  /* それより辞書順で大きい順列が存在しないときに抜ける
  以上の場合だと
    2,3,1
    3,1,2
    3,2,1
    で終わる。
    全て回すときは昇順に並べること
  */
}

void builtin_popcount() {
  // 整数 x を二進数で表したとき、1 であるようなビットの個数を返す関数
  long long x,y;
  x=127; y=128;
  cout << __builtin_popcountll(x) << endl;
  cout << __builtin_popcountll(y) << endl;
}

void bitsetFunc() {
  // 例 1: 長さ 250000 の bitset（250000 桁の 2 進数だと思ってよい）を定義する。
  bitset<250000> bs1;
  // 例 2: 長さ 8 の bitset を定義する。整数から初期化を行う。
  bitset<8> bs2(131); // 7 ビット目から 0 ビット目への順番で、10000011 となる。
  // 例 3: 長さ 8 の bitset を定義する。2 進数から初期化を行う。
  bitset<8> bs3("10000011"); // 7 ビット目から 0 ビット目への順番で、10000011 となる。
  // 例 4: 例 3 とやってることは変わらない。ただ bitset の長さが増えただけ。
  bitset<2000> bs4("10000011"); // 1999 ビット目から 0 ビット目の順番で、0...010000011 となる。

  bs2.set(2);
  cout << bs2 << endl;
  cout << (bs2 | bs3) << endl; // or
  cout << (bs2 & bs3) << endl; // and
  cout << (bs2 ^ bs3) << endl; // xor
}



int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  find();
  return 0;
}
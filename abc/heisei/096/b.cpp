#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
int A, B, C, K;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B >> C >> K;

    int a1 = A*pow(2, K) + B + C;
    int a2 = B*pow(2, K) + A + C;
    int a3 = C*pow(2, K) + B + A;

    int ab = max(a1, a2);
    int abc = max(ab, a3);
    cout << abc << endl;
    return 0;
}
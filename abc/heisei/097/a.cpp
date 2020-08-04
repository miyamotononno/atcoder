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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a,b,c,d;
    cin >> a >> b>> c>> d;
    string no = "No";
    string yes = "Yes";
    if (abs(c-a) <= d){
        cout << yes << endl;
        return  0;
    }
    if (abs(b-a) <= d & abs(c-b) <= d){
        cout << yes << endl;
        return  0; 
    }

    cout << no << endl;
    return 0;
}
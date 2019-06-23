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
using namespace std;
int N;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<pair <int, int> > X(N);
    rep(i, N)cin >> X[i].second >> X[i].first;
    
    sort(X.begin(), X.end());
    int now = 0;
    rep(i, N){
        if(X[i].first < X[i].second + now){
            cout << "No" <<endl;
            return 0;
        }
        now += X[i].second;
    }

    cout << "Yes" << endl;
    return 0;
}
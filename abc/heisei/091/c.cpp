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
    vector<pair <int, int> > red(N);
    vector<pair <int, int> > blue(N);
    rep(i, N) cin >> red[i].first >> red[i].second;
    rep(i, N) cin >> blue[i].first >> blue[i].second;

    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());
    int cnt= 0;
    rep(i,N){
        int selected_idx = -1;
        bool flag = false;
        rep(j,N){
            if((red[j].first < blue[i].first) &(red[j].second < blue[i].second)){
                if (selected_idx  < 0){
                    selected_idx= j;
                    flag = true;
                    continue;
                }
                if (red[selected_idx].second < red[j].second) selected_idx = j;
            }
        }
        if(flag){
            red[selected_idx].first = 300;
            red[selected_idx].second = 300;
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
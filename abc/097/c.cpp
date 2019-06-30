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
string s, ans;
int K;

int search(vector<int> &T, int r){
    vector<string> C;
    int a = s.size();
    rep(i, T.size()){
        for(int j=1; j<=min(r, a - T[i]); j++){
            C.push_back(s.substr(T[i], j));
        }
    }
    sort(C.begin(), C.end());
    C.erase(unique(C.begin(), C.end()), C.end());
    if(C.size() < r) return r - C.size();
    
    ans = C[r-1];
    return 0;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> K;
    vector<pair<char, int> > S(s.size());
    rep(i, s.size()){
        S[i].first = s[i];
        S[i].second = i;
    }

    sort(S.begin(), S.end());
    if(K==1){
        cout << S[0].first << endl;
        return 0;
    }
    int t = 0;
    while(t < S.size()){
        vector<int> T;
        char trgt = S[t].first;
        T.push_back(S[t].second);
        t++;
        while((t < S.size()) & (trgt == S[t].first)){
            T.push_back(S[t].second);
            t++;
        }
        K = search(T, K);
        if(K == 0) break;
    }

    cout << ans << endl;
    return 0;
}
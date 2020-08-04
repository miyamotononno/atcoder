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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string S, T, ans;
    cin >> S >> T;
    int l = T.size();
    if (S.size() < l){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    rep(i,S.size()-l+1){
        string S2 = S.substr(i,l);
        rep(j, l){
            if (S2[j] == '?' || S2[j] == T[j]){
                if (j == l-1){
                    string tmp = S;
                    S.replace(i,l,T);
                    rep(k, S.size()) if(S[k] == '?') S[k]='a';
                    if(ans.empty()) ans=S;
                    else ans=min(ans,S);
                    S=tmp;
                    break;
                }else continue;
            }else break;
        }
    }
    if (ans.empty()) cout << "UNRESTORABLE" << endl;
    else cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
#include "module.hpp"

using namespace std;

template <typename T> T calcMaximumHistogram(vector<T> hist) {
    hist.push_back(T(0));
    stack<Rect<T>> st;
    T maxArea = T(0);
    Rect<T> rect;
    for (int w=0; w<hist.size(); w++) {
        rect.h = hist[w];
        rect.w = T(w);
        if (st.empty() || st.top().h < rect.h) {
          st.push(rect);
          continue;
        }
        if (st.top().h > rect.h) {
          T target = w;
          while(!st.empty() && st.top().h >= rect.h) {
            Rect<T> preRect = st.top(); st.pop();
            target = preRect.w;
            T area = preRect.h*(w-target);
            maxArea = max(area, maxArea);
          }
          rect.w = target;
          st.push(rect);
        }

    }
    return maxArea;
}

/*
これを書かないと、テンプレートの実態が存在しない。そのため、明示的なインスタンス化を行う必要がある。
詳しくはこちら↓
https://marycore.jp/prog/xcode/undefined-symbols-for-architecture-x86-64/#%E3%83%86%E3%83%B3%E3%83%97%E3%83%AC%E3%83%BC%E3%83%88%E3%81%AE%E5%AE%9F%E4%BD%93%E3%81%8C%E5%AD%98%E5%9C%A8%E3%81%97%E3%81%AA%E3%81%84
*/
template int calcMaximumHistogram<int>(vector<int> hist);
template long long calcMaximumHistogram<long long>(vector<long long> hist);
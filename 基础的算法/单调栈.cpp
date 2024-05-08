#include <bits/stdc++.h>

using namespace std;

int n;
stack<int> S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin>>n;
    //计算出每个数左边比他更小的数
    for (int i=0; i<n; i++) {
        int x; cin>>x;
        while(!S.empty() && S.top() >= x) S.pop();
        cout<<(!S.empty() ? S.top() : -1)<<" ";
        S.push(x);
    }

}
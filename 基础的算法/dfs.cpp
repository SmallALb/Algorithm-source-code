#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int n;
int path[N];
int bit = 0;
//dfs求全排列
void dfs(int i) {
    if (i == n) {
        for (int j = 0; j<n; j++) cout<<path[j]<<" ";
        cout<<"\n";
        return;
    }

    for (int j =1; j<=n; j++) {
        if (!(bit & 1<<j)) {
            path[i] = j;
            bit |= 1<<j;
            dfs(i+1);
            bit ^= 1<<j;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;

    dfs(0);

}
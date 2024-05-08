#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];

//dfs解法
void dfs(int i) {
    if (i == n) {
        for (int j = 0; j<n; j++) cout<<g[j]<<"\n";
        cout<<"\n";
        return;
    }

    for (int j =0; j<n; j++) {
        if (!col[j] && !dg[i+j] && !udg[n - i + j]) {
            g[i][j] = 'Q';
            col[j] = dg[i+j] = udg[n-i+j] = 1;
            dfs(i+1);
            col[j] = dg[i+j] = udg[n-i+j] = 0;
            g[i][j] = '.';
        }
    }
}

//更为原始的dfs
void __dfs(int x, int y, int s) {
    if (y == n) y=0, x++;
    if (x == n) {
        if (s == n) {
            for (int i =0; i<n; i++) cout<<g[i]<<"\n";
            cout<<"\n";
        }
        return;
    }

    __dfs(x, y+1, s);

    if (!row[x] && !col[y] && !dg[x+y] && !udg[x-y+n]) {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = 1;
        __dfs(x, y+1, s+1);
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = 0;
        g[x][y] = '.';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;

    for (int i=0; i<n; i++){
        for (int j = 0; j<n; j++) g[i][j] = '.';
    }


    __dfs(0, 0,0);

}
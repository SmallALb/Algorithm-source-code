#include <bits/stdc++.h>

using namespace std;

using PII = pair<int, int>;

const int N = 101;

int n, m;
int g[N][N];
int vis[N][N];

int bfs() {
    queue<PII> Q;
    Q.push({0, 0});
    memset(vis, -1, sizeof vis);
    vis[0][0] = 0;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while(!Q.empty()) {
        auto t = Q.front();
        Q.pop();
        for (int i =0; i<4; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (y >= 0 && y < n && x >=0 && x<m && !g[y][x] && vis[y][x] == -1) {
                vis[y][x] = vis[t.second][t.first] + 1;
                Q.push({x, y});
            }
        }
    }

    return vis[n-1][m-1];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin>>n>>m;

    for (int y = 0; y<n;  y++) {
        for (int x = 0; x<m; x++) cin>>g[y][x];
    }

    cout<<bfs();

}
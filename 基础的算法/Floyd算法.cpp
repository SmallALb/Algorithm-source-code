#include <bits/stdc++.h>

using namespace std;
const int N = 210, INF = 1e9;

int dis[N][N], n, m, Q;

void floyd() {

    for (int k = 1; k<=n; k++) {
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j<=n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin>>n>>m>>Q;


    for (int i =1; i<=n; i++) {
        for (int j = 1; j <= n; j++) dis[i][j] = (i == j) ? 0 : INF;
    }

    while(m--) {

        int a, b, w; cin>>a>>b>>w;
        dis[a][b] = min(dis[a][b], w);

    }

    floyd();

    while(Q--) {
        int a,b; cin>>a>>b;
        cout<<(dis[a][b] > INF/2 ? "impossible" : to_string(dis[a][b]))<<"\n";
    }

}
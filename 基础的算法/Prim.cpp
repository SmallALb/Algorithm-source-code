#include <bits/stdc++.h>

using namespace std;

const int N  = 510, INF = 0x3f3f3f3f;

int n, m;

int g[N][N];
int dis[N];
bool vis[N];


int prim() {
    memset(dis, 0x3f, sizeof dis);

    int res = 0;
    for (int i =0; i<n; i++) {
        int t = -1;
        for(int j = 1; j<=n; j++) {
            if (!vis[j] && (t == -1 || dis[t] > dis[j])) t = j;
        }

        if (i && dis[t] == INF) return INF;
        if (i) res += dis[t];

        for (int j = 1; j<=n; j++) dis[j] = min(dis[j], g[t][j]);

        vis[t] = true;
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    memset(g, 0x3f, sizeof g);

    cin>>n>>m;
    while(m--) {
        int a,b,c; cin>>a>>b>>c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int t = prim();
    cout<<(t == INF ? "impossible" : to_string(t));
}
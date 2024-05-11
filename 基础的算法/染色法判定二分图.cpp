#include <bits/stdc++.h>
using namespace std;

const int N = 100010;


vector<vector<int>> mp;
int colors[N];
bool vis[N];

int n, m;

bool dfs(int i, int color) {
    colors[i] = color;
    vis[i] = 1;

    for (auto x : mp[i]) {
        if (!colors[x]) if (!dfs(x, 3-color)) return false;

        if (colors[x] == color) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin>>n>>m;
    mp.resize(n+1);
    while (m -- ) {
        int a, b;cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    for (int i=1; i<=n; i++) {
        if (!colors[i]) {
            if(!dfs(i, 1)) {
                cout<<"No";
                return 0;
            }
        }
    }

    cout<<"Yes";
}
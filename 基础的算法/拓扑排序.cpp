#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m;
vector<vector<int>> mp;
queue<int> Q;
vector<int> path;
int ins[N] = {0};

void bfs() {
    while(!Q.empty()) {
        int t = Q.front();
        path.push_back(t);
        Q.pop();
        for (auto x : mp[t]) {
            ins[x]--;
            if (!ins[x]) Q.push(x);
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin>>n>>m;
    mp.resize(n+1);
    while(m--) {
        int y, x; cin>>y>>x;
        mp[y].push_back(x);
        ins[x]++;
    }
    for (int i=1; i<=n; i++) if (!ins[i]) Q.push(i);
    bfs();

    if (path.size() != n) cout<<-1;
    else for (auto x : path) cout<<x<<" ";

}

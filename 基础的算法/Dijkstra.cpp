#include <bits/stdc++.h>
using namespace std;

const int N = 150010;

using PII = pair<int, int>;

int n, m;
vector<vector<PII>> mp;


int Dijkstra() {
    priority_queue<PII, vector<PII>, greater<>> p_Q;
    p_Q.push({ 0, 1 });
    vector<int>  dis(n+1, INT_MAX);
    dis[1] = 0;
    while (!p_Q.empty()) {
        auto T = p_Q.top();
        p_Q.pop();
        int d = T.first, idx = T.second;
        if (idx == n) return d;
        if (d > dis[idx]) continue;
        for (auto x : mp[idx]) {
            int d_ = x.second, to = x.first;
            if (d + d_ < dis[to]) {
                dis[to] = d + d_;
                p_Q.push({ dis[to], to });
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    mp.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int to, from, d; cin >> from >> to >> d;
        mp[from].push_back({ to, d });
    }

    cout << Dijkstra();
}
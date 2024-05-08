
#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;

const int N = 100010;
int dis[N];
bool ins[N];
int n, m;
vector<vector<PII>> mp;
bool bfs() {
    memset(dis, 0x3f3f3f, sizeof dis);
    queue<int> Q;
    Q.push(1);
    ins[1] = 1;
    dis[1] = 0;
    while(!Q.empty()) {
        int T = Q.front();
        Q.pop();
        ins[T] = 0;

        for (auto path : mp[T]) {
            if (path.second + dis[T] < dis[path.first]) {
                dis[path.first] = path.second + dis[T];
                if (!ins[path.first]) {
                    Q.push(path.first);
                    ins[path.first] = 1;
                }
            }
        }
    }

    return dis[n] != 1061109567;
}

//spaf能够用在有负权边的图上

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    mp.resize(n+1);
    while(m--) {
        int from, to, d; cin>>from>>to>>d;
        mp[from].push_back({to, d});
    }

    cout<<(bfs() ? to_string(dis[n]) : "impossible");
}
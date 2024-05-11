#include <bits/stdc++.h>
using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
vector<vector<int>> mp(N);
int match[N];
bool vis[N];
//匈牙利算法，寻找二分图最大匹配
bool find(int i) {
    for (auto x : mp[i]) {
        if (!vis[x]) {
            vis[x] = 1;
            if (match[x] == 0 || find(match[x])) {
                match[x] = i;
                return true;
            }
        }
    }
    return false;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n1>>n2>>m;

    while (m -- ) {
        int a, b; cin>>a>>b;
        mp[a].push_back(b);
    }

    int res = 0;
    for (int i=1; i<=n1; i++) {
        memset(vis, false, sizeof vis);
        if (find(i)) res++;
    }

    cout<<res;
}
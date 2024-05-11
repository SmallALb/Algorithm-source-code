#include <bits/stdc++.h>
using namespace std;

const int N = 100010, M = 200010;

int n, m, fa[N];


struct date{
    int from, to, w;
}arr[M];


int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]);}

//基于并查集将每个节点连为一棵树

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin>>n>>m;

    for (int i = 0; i<m; i++) {
        int a, b, w; cin>>a>>b>>w;
        arr[i] = {a, b, w};
    }

    sort(arr, arr+m, [](auto a, auto b)->bool {
        return a.w < b.w;
    });

    for (int i =0; i<=n; i++) fa[i] = i;

    int cnt = 0, res = 0;
    for (int i = 0; i<m; i++) {
        int from = arr[i].from, to = arr[i].to, w = arr[i].w;
        from = find(from), to = find(to);
        if (from != to) {
            fa[to] = from;
            res += w;
            cnt++;
        }
    }

    cout<<(cnt < n-1 ? "impossible" : to_string(res));
}

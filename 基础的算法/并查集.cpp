#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int fa[N], Size[N];
int n, m;

int find(int x) {
    return fa[x] = (fa[x]!=x) ? find(fa[x]) : x ;
}
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        fa[i] = i;
        Size[i] = 1;
    }

    while(m--) {
        string op;
        cin>>op;
        int a, b;

        if (op == "C") {
            cin>>a>>b;
            if (find(a) == find(b)) continue;
            Size[find(b)] += Size[find(a)];
            fa[find(a)] = find(b);

        }
        else if (op == "Q1") {
            cin>>a>>b;
            cout << (find(a) == find(b) ? "Yes" : "No") << "\n";
        }
        else {
            cin>>a;
            cout<<Size[find(a)]<<"\n";
        }
    }

}
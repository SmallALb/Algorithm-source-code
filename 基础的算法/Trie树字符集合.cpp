#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n;

int son[N][26], cnt[N], idx=0;
//Trie树插入
void insert(string str) {
    int p = 0;
    for (int i=0; i<str.size(); i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p] ++;
}
//Trie树查找
int query(string str) {
    int p = 0;
    for (int i=0; i<str.size(); i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }

    return cnt[p];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin>>n;
    while(n--) {
        string op, ans;
        cin>>op>>ans;
        if (op == "I") insert(ans);
        else cout<<query(ans)<<"\n";
    }
}
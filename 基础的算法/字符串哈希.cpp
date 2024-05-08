#include <bits/stdc++.h>
using namespace std;

using ULL = unsigned long long;
//原理是通过将字符串的每一个字符转化为一个p进制的数，这个p进制数就是这个哈希表的键值，131 或者 13331的冲突情况是最小的
const int N = 100010, P = 131;

ULL h[N], p[N];

int n, m;
string str;

ULL get(int l, int r) {
    return h[r] - h[l-1]*p[r-l+1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    p[0] = 1;
    cin>>n>>m>>str;

    for (int i =1; i<=n; i++) {
        h[i] = h[i-1]*P + str[i-1];
        p[i] = p[i-1]*P;
    }
    while(m--) {
        int l1, r1, l2, r2;cin>>l1>>r1>>l2>>r2;
        cout<<(get(l1, r1) == get(l2, r2) ? "Yes" : "No")<<"\n";
    }
}
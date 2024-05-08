#include <bits/stdc++.h>
using namespace std;

const int N = 200003, null = 0x3f3f3f;

int h[N], n;

//开放寻址法
int find(int x) {
    int k = (x%N+N)%N;
    while (h[k] != null && h[k] != x) {
        k++;
        if (k == N) k = 0;
    }
    return k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;

    fill(h, h+N, null);

    while(n--) {
        char input; cin>>input;
        int x; cin>>x;
        int i = find(x);
        if (input == 'I') h[i] = x;
        else cout<<(h[i]!=null ? "Yes" : "No")<<"\n";
    }

}
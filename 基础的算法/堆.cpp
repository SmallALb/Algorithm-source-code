#include <bits/stdc++.h>
using namespace std;

//最小堆的实现
const int N = 100010;

// h[N]存储堆中的值, h[1]是堆顶，x的左儿子是2x, 右儿子是2x + 1
// ph[k]存储第k个插入的点在堆中的位置
// hp[k]存储堆中下标是k的点是第几个插入的
int h[N], ph[N], hp[N],s = 0;

int n, m;


//堆的交换
void head_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

//堆下推
void down(int i) {
    int t = i;
    if (i*2 <= s && h[i*2] < h[t]) t = i*2;
    if (i*2+1 <= s && h[i*2+1] < h[t]) t = i*2 + 1;
    if (i != t) {
        head_swap(i, t);
        down(t);
    }
}
//堆上推
void up(int i) {
    while( i/2 && h[i/2]> h[i]) {
        head_swap(i/2, i);
        i /= 2;
    }
}
//删除最小值
void delete_min() {
    h[1] = h[s];
    s--;
    down(1);
}


int main() {
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>h[i];

    s = n;

    for (int i = n/2; i; i--) down(i);

    while(m--) {
        cout<<h[1]<<" ";
        delete_min();
    }

}
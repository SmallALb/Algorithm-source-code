#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int n, m;
int arr[N], pre[N], dev[N];
int arr_2[N][N], pre_2[N][N], dev_2[N][N];

//一维差分的插入
void insert(int l, int r, int c) {
    dev[l] += c;
    dev[r+1] -= c;
}

//二维差分的插入
void insert2D(int x1, int y1, int x2, int y2, int c) {
    dev_2[y1][x1] += c;
    dev_2[y1][x2+1] -= c;
    dev_2[y2+1][x1] -= c;
    dev_2[y2+1][x2+1] += c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//=========================<一维前缀和>===================================================
//    cin>>n>>m;
//    for (int i=1; i<=n; i++) cin>>arr[i];
//    for(int i=1; i<=n; i++) pre[i] = pre[i-1] + arr[i];
//    int l, r; cin>>l>>r;
//    cout<<pre[r] - pre[l-1]<<"\n";


//=========================<二维前缀和>===================================================
//    cin>>n>>m;
//    for (int i=1; i<=n; i++) {
//        for (int j=1; j<=m; j++) {
//            cin>>arr_2[i][j];
//        }
//    }
//
//    for (int i=1; i<=n; i++) {
//        for (int j=1; j<=n; j++) {
//            pre_2[i][j] =pre_2[i-1][j] + pre_2[i][j-1] -pre_2[i-1][j-1] + arr_2[i][j];
//        }
//    }
//
//    int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
//    cout<<pre_2[y2][x2] - pre_2[y1-1][x2] - pre_2[y2][x1-1] + pre_2[y1-1][x1-1];


//=========================<一维前差分>===================================================
//    cin>>n;
//    for (int i=1; i<=n; i++) cin>>arr[i];
//    fill(dev, dev+n, 0);
//    for (int i=1; i<=n; i++) {
//        insert(i, i, arr[i]);
//    }
//
//    int l, r, c; cin>>l>>r>>c;
//    insert(l, r, c);
//
//    for (int i=1; i<=n; i++) arr[i] = dev[i] + arr[i-1];
//
//    for (int i=1; i<=n; i++) cout<<arr[i]<<" ";


//=========================<二维前差分>===================================================
//    cin>>n>>m;
//    for (int i=1; i<=n; i++) {
//        for (int j=1; j<=m; j++) {
//            cin>>arr_2[i][j];
//        }
//    }
//    fill(dev_2[0], dev_2[n]+m, 0);
//
//    for (int i=1; i<=n; i++) {
//        for (int j=1; j<=m; j++) {
//            insert2D(j,i,j,i, arr_2[i][j]);
//        }
//    }
//
//    int x1, y1, x2, y2, c; cin>>x1>>y1>>x2>>y2>>c;
//    insert2D(y1, x1, y2, x2, c);
//
//    for (int i=1; i<=n; i++) {
//        for (int j=1; j<=m; j++) {
//            arr_2[i][j] = arr_2[i-1][j] + arr_2[i][j-1] + dev_2[i][j] - arr_2[i-1][j-1];
//        }
//    }
//
//    for (int i=1; i<=n; i++) {
//        for (int j=1; j<=m; j++) {
//            cout<<arr_2[i][j]<<" ";
//        }
//        cout<<"\n";
//    }

}
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N= 300010;

int n, m;
int arr[N], pre[N];

vector<int> alls;
vector<PII> add, query;

int find(int x) {
    int l = 0, r=alls.size() -1;
    while(l<r) {
        int mid = l+r >> 1;
        if (alls[mid] >= x) r =mid;
        else l = mid+1;
    }
    return r + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        int x, c;
        cin>>x>>c;
        add.push_back({x, c}); //记录添加的数上要加上C

        alls.push_back(x);    //记录每一个添加的数
    }

    for (int i=0; i<m; i++) {
        int l, r;
        cin>>l>>r;
        query.push_back({l, r}); //添加要查询的区间

        alls.push_back(l);
        alls.push_back(r);
    }
    //去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    //将插入的值离散化
    for (auto i : add) {
        int x = find(i.first);
        arr[x] += i.second;
    }
    cout<<"\n";
    //前缀和预处理
    for(int i=1; i<=alls.size(); i++) pre[i] = pre[i-1] + arr[i];

    for (auto i : query) {
        int l = find(i.first), r = find(i.second);
        cout<< pre[r] - pre[l-1]<<"\n";
    }
}
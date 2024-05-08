#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+10;
int n, k;
deque<int> Q;
int arr[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin>>n>>k;
    //滑动窗口
    for (int i=0; i<n; i++) cin>>arr[i];

    for (int i=0; i<n; i++) {
        while(!Q.empty() && arr[Q.back()] >= arr[i]) Q.pop_back(); //判断队列的尾的数是不是大于了现在要推入队列的数
        Q.push_back(i);
        if (!Q.empty() && Q.front() < i-k+1) Q.pop_front(); //判断是否划出窗口
        if (i >= k-1) cout<<arr[Q.front()]<<" ";

    }
    cout<<"\n";
    Q.clear();
    for (int i=0; i<n; i++) {
        while(!Q.empty() && arr[Q.back()] <= arr[i]) Q.pop_back();
        Q.push_back(i);
        if (!Q.empty() && Q.front() < i-k+1) Q.pop_front();
        if (i >= k-1) cout<<arr[Q.front()]<<" ";
    }

}
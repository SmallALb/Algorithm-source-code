#include <bits/stdc++.h>
using namespace std;
//输出二进制
void getBits(int n) {
    for (int i=min(n/2, 31); ~i; i--) cout<<(n>>i & 1);
    cout<<"\n";
}
//输出二进制的最低位置
int lowbit(int n) {
    return n & (-n);
}

int num, k=0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>num;
    getBits(num);
    //利用lowbit可以计算这个数的二级制数一共有多少个1
    while (num) {
        num -= lowbit(num);
        k++;
    }
    cout<<k;

}
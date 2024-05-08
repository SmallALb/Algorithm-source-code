#include <bits/stdc++.h>

using namespace std;

string A, B;

bool kmp(string a, string b) {
    bool flag = 0;
    if (a.size() < b.size()) return kmp(b, a);

    int arr[a.size()];
    //前后缀的求取
    for (int i=1, j=0; i<a.size(); i++) {

        while(j && a[i] != a[j]) j = arr[j];
        if (a[i] == a[j]) j++;
        arr[i] = j;
    }

    for (int i=0, j =0; i<a.size(); i++) {
        while(j && a[i] != b[j]) j = arr[j];
        if (a[i] == b[j]) j++;
        if (j == b.size()){
            cout<<i-b.size()+1<<" ";
            j = arr[j];
            flag = 1;
        }
    }
    cout<<"\n";
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>A>>B;
    cout<<(kmp(A,B) ? "YES" : "NO");
}
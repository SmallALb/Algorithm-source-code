#include <bits/stdc++.h>
using namespace std;
//快排模板
 void Qsort(int left, int right, int* arr) {
     if (left >= right) return;
    int x = arr[left];
    int l = left-1, r = right+1;
    while(l<r) {
        do l++; while(arr[l] < x);
        do r--; while(arr[r] > x);
        if (l<r) swap(arr[l], arr[r]);
    }
     Qsort(left, r, arr), Qsort(r+1, right, arr);
 }

//归并排序模板
void Tsort(int left, int right, int* arr) {
   int tmp[right];
   function<void(int, int)> sort = [&](int le, int ri) {
       if (le >= ri) return;
       int mid = le+ri >> 1;
       sort(le, mid), sort(mid+1, ri);
       int l = le, r = mid+1, k =0;
       while(l <= mid && r  <= ri) tmp[k++] = (arr[l] <= arr[r]) ? arr[l++] : arr[r++];
       while(l <= mid) tmp[k++] = arr[l++];
       while(r <= ri) tmp[k++] = arr[r++];

       for (int i=le, j=0; i<=ri; i++, j++) arr[i] = tmp[j];
   };
   sort(left, right);
 }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int arr[11];
    for (int i=0; i<11; i++) {
        cin>>arr[i];
    }
    Tsort(0, 10, arr);
    for (auto x : arr) cout<<x<<" ";
    cout<<"\n";

}
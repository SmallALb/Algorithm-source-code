#include <bits/stdc++.h>
using namespace std;
//判断A是不是大于B
bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return a.size()>b.size();
    for (int i=a.size()-1; i>=0; i--)
        if (a[i] != b[i]) return a[i] > b[i];
    return 1;
}

//高精度加法
vector<int> add(const vector<int>& a, const vector<int>& b) {
    int t = 0;
    vector<int> c;
    if (a.size() < b.size()) return add(b, a);

    for (int i=0; i<a.size() || i<b.size() || t; i++) {
        if (i < a.size()) t += a[i];
        if (i <b.size()) t+= b[i];
        c.push_back(t%10);
        t /= 10;
    }


    return c;
}

//高精度减法
vector<int> sub(const vector<int>& a, const vector<int>& b) {
    int t =0;
    vector<int> c;
    for (int i=0; i<a.size(); i++) {
        t = a[i] -t;
        if (i < b.size()) t -= b[i];
        c.push_back((t+10) % 10);
        t = t<0 ? 1 : 0;
    }
    while(c.size()>1 && !c.back()) c.pop_back();

    return c;
}

//高精度乘法
vector<int> mul(const vector<int>& a, const long long& b) {
    long long t = 0;
    vector<int> c;
    for (int i=0; i<a.size() || t; i++) {
        if (i<a.size()) t += a[i]*b;
        c.push_back(int(t%10));
        t /= 10;
    }
    return c;
}

//高精度除法
vector<int> div(const vector<int>& a, long long b, long long& r) {
    vector<int> c;
    r = 0;
    for (int i=a.size()-1; ~i; i--) {
        r = r*10 + a[i];
        c.push_back(int(r/b));
        r %= b;
    }
    reverse(c.begin(), c.end());
    while (c.size()>1 && !c.back()) c.pop_back();
    return c;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string num1, num2; cin>>num1>>num2;
    long long r;
    vector<int> A, B;
    for (int i=num1.size()-1; i>=0; i--) A.push_back(num1[i]-'0');
    for (int j=num2.size()-1; j>=0; j--) B.push_back(num2[j] -'0');
    //auto C = add(A, B);
    //auto C = cmp(A,B) ? sub(A,B) : sub(B,A);
    //auto C = mul(A, 114514191981000000);
    auto C = div(A, 3, r);

    for (int i=C.size()-1; i>=0; i--) cout<<C[i];
    cout<<"\n";
    cout<<r;
}
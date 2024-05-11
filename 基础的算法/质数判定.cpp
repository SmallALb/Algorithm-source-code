#include <iostream>

using namespace std;

int n;

bool is(int x) {
    if (x < 2) return 0;
    for (int i =2; i<= x/i; i++) if (x % i == 0) return 0;
    return 1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    while(n--) {
        int a; cin>>a;
        cout<<(is(a) ? "Yes" : "No")<<"\n";
    }

}
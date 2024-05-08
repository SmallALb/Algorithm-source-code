#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n;
vector<PII> segs;

void merge(vector<PII>& s) {
    vector<PII> res;
    sort(s.begin(), s.end());
    int st = -2e9, ed = -2e9;
    for (auto seg : s) {
        if (ed<seg.first) {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);
    }
    if (st != -2e9) res.push_back({st, ed});

    s = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i=0; i<n; i++) {
        int l, r;cin>>l>>r;
        segs.push_back({l, r});
    }

    merge(segs);

    cout<<segs.size() <<"\n";

}
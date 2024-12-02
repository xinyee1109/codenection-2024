#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> h;
    vector<int> v;

    for(int i=0; i < n; i++){
        int d;
        cin >> d;
        if (i % 2 == 0){
            h.push_back(d);
        }else{
            v.push_back(d);
        }
    }

    int offset = 10001;
    vector<bool> dp_h(20005);
    dp_h[offset + h[0]] = true;
    for(int i=1; i < size(h); i++){
        vector<bool> temp(20005);
        for(int j=0; j < size(dp_h); j++){
            if (dp_h[j]){
                temp[j + h[i]] = true;
                temp[j - h[i]] = true;
            }
        }
        swap(temp, dp_h);
    }

    bool reachable = dp_h[offset + x];

    vector<bool> dp_v(20005);
    dp_v[offset] = true;
    for(int i=0; i < size(v); i++){
        vector<bool> temp(20005);
        for(int j=0; j < size(dp_v); j++){
            if (dp_v[j]){
                temp[j + v[i]] = 1;
                temp[j - v[i]] = 1;
            }
        }
        swap(temp, dp_v);
    }

    reachable &= dp_v[offset+y];

    cout << (reachable ? "YES": "NO") << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}
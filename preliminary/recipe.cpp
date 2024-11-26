#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m, k; 
    cin >> n >> m >> k;
    
    int match = 0;
    map <int, int> a;
    vector <int> b;
    map <int, int> c;
    for (int i = 0; i < n; i++){
        int x; 
        cin >> x;
        b.push_back(x);
    }
    
    auto add = [&](int x){
        if (c[x] < a[x]){
            match++;
        }
        c[x]++;
    };
    
    auto erase = [&](int x){
        if (c[x] <= a[x]){
            match--;
        }
        c[x]--;
    };
    
    int ans = 0;
    for (int i = 0; i < m; i++){
        int x; 
        cin >> x;
        a[x]++;
    }
    
    for (int i = 0; i < m; i++){
        add(b[i]);
    }
    
    if (match >= k) ans++;
    
    for (int i = m; i < n; i++){
        add(b[i]);
        erase(b[i - m]);
        if (match >= k) ans++;
    }
    
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

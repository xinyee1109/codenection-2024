#include <bits/stdc++.h>

using namespace std;

void solve(){
    string a, b;
    cin >> a >> b;

    int p1 = 0, p2 = 0;
    while (p1 < size(a) && p2 < size(b)){
        if (a[p1] == b[p2] || a[p1] == '*'){
            p2++;
        }
        p1++;
    }

    cout << (p2 == size(b) ? "YES" : "NO") << '\n';
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

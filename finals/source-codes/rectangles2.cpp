#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> freq(101, vector<int> (101));

    for(int i{}; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int j{a}; j < b; j++)
           for(int k{c}; k < d; k++)
               freq[j][k] = 1;
    }

    int sm = 0;
    for(int i{}; i <= 100; i++){
        for(int j{}; j <= 100; j++) sm += freq[i][j];
    }

    cout << sm;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

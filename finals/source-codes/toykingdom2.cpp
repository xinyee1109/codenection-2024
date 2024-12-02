#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;
vector<int> adj[MX];
bool vis[MX];

void dfs(int cur){
    if (vis[cur]){
        return;
    }

    vis[cur] = 1;
    for(auto& i : adj[cur]){
        dfs(i);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i{}; i < m; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }

    int cnt = 0;
    for(int i{}; i < n; i++){
        if (!vis[i]){
            cnt++;
            dfs(i);
        }
    }

    cout << m - (n-1-(cnt-1)) << ' ' << cnt-1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

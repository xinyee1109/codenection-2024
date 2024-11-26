#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MX = 3e5 + 5;

long long fact[MX];

long long modpow(long long n, long long p){
    if (!p) return 1;
    long long sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    return (p % 2 ? n * sq : sq) % MOD;
}

void gen_fact(){
    fact[0] = 1;
    fact[1] = 1;
    for(long long i{2}; i < MX; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
}

long long ncr(long long n, long long r){
    long long num = (fact[n] * modpow(fact[n-r], MOD-2)) % MOD;;
    long long denom = fact[r];
    return (num * modpow(denom, MOD-2)) % MOD;
}

long long compute_interval(pair<int,int> prev, pair<int,int> cur){
    if ((cur.first - prev.first - 1) == 1){
        return min(prev.second, cur.second) - 1;
    }

    long long total = 0;
    for(int i{min(prev.second, cur.second)-1}; i >= 1; i--){
        long long n = (cur.first-prev.first-1)-1;
        long long r = ((prev.second-1)-i+1) + ((cur.second-1)-i);
        total = (total + ncr(n+r-1, n)) % MOD;
    }

    return total;
}

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& i : a) cin >> i;

    long long total = 1;
    pair<int,int> prev{-1, 1e5+1};
    for(int i{}; i < n; i++){
        if (a[i] != -1){
            pair<int,int> cur{i, a[i]};
            total = (total * compute_interval(prev, cur)) % MOD;        
            swap(prev, cur);
        }
    }

    total = (total * compute_interval(prev, {n, 1e5+1})) % MOD;

    cout << total;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    gen_fact();
    solve();
}

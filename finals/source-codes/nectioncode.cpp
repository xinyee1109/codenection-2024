#include <bits/stdc++.h>

using namespace std;

const int MOD =  998244353;
const int MX = 1 << 20;
long long fact[MX];
 
void gen_fact(){
    fact[0] = 1;
    fact[1] = 1;
    for(long long i{2}; i < MX; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
}
 
long long modpow(long long n, long long p){
    if (!p) return 1;
    long long sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    return (p % 2 ? n * sq : sq) % MOD;
}

bool at_losing_stage(int team, int stage){
    if (team == -1) return false;
    if (team == 0) return stage == 0;

    // find MSB
    // MSB position is the losing stage
    int mx = 0;
    for(int i{}; i < 20; i++){
        if ((1 << i) & team) mx = i;
    }

    return stage == (mx+1);
}

void solve(){
    int n;
    cin >> n;

    vector<int> matchups(1 << n, -1);
    for(int i{}; i < (1 << n); i++){
        int team;
        cin >> team;
        if (team == -1) continue;
        matchups[i] = team-1;
    }
    
    long long total = 1;
    // iterate through each stage, starting from the first stage
    for(int i{n}; i >= 1; i--){
        int total_matchups = (1 << i);

        vector<int> next_matchups;
        int cnt_lose_fixed = 0;
        int cnt_fixed = 0;
        // iterate through each matchup
        for(int j{}; j < total_matchups; j+=2){
            // make sure matchups[j] is always smaller for convenience
            if (matchups[j] > matchups[j+1]){
                swap(matchups[j], matchups[j+1]);
            }

            // if both teams are fixed
            if (matchups[j] != -1 && matchups[j] != -1){
                // impossible case
                if (at_losing_stage(matchups[j], i) == at_losing_stage(matchups[j+1], i)){
                    cout << 0;
                    return;
                }else{
                    cnt_lose_fixed++;
                    cnt_fixed++;
                    // advance the team that takes fewer time to solve
                    next_matchups.push_back(matchups[j]);
                }
            }

            // if only one team is fixed in the matchup
            if (matchups[j] == -1 && matchups[j+1] != -1){
                // if the fixed team must lose
                if (at_losing_stage(matchups[j+1], i)){
                    cnt_lose_fixed++;
                    next_matchups.push_back(-1);
                }else{
                    next_matchups.push_back(matchups[j+1]);
                }
                cnt_fixed++;
            }

            // if both teams are unassigned
            if (matchups[j] == -1 && matchups[j+1] == -1){
                next_matchups.push_back(-1);
            }
        }
        
        long long unassigned_losing_teams = (1 << (i-1)) - cnt_lose_fixed;
        long long unassigned_matchups = (1 << (i-1)) - cnt_fixed;
        long long losing_team_permutation = fact[unassigned_losing_teams];
        long long matchup_permutation = modpow(2, unassigned_matchups);

        total = ((total * losing_team_permutation) % MOD * matchup_permutation) % MOD;

        swap(next_matchups, matchups);
    }

    cout << total;
}

int main(){
    gen_fact();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
